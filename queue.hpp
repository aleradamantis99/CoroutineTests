#include <queue>
#include <cppcoro/single_consumer_event.hpp>
#include <cppcoro/io_service.hpp>
#include <cppcoro/task.hpp>
#include "single_thread_event.hpp"
namespace asyncio
{
namespace cor = cppcoro;
template <typename T>
class Queue
{
using Locks = asyncio::single_thread_event;
public:
    Queue(cor::io_service& io, size_t sz = 0):
        max_size(sz),
        finished(true),
        srvc(&io)
    {}
    size_t maxsize() const
    {
        return max_size;
    }
    size_t size() const
    {
        return q.size();
    }
    bool full() const
    {
        return (maxsize() <= 0? false:size() >= maxsize());
    }

    bool empty() const
    {
        return q.empty();
    }
    cor::task<> put(const T& item)
    {
        while (full())
        {
            co_await putters.emplace();
        }
        put_nowait(item);
    }
    void put_nowait(const T& item)
    {
        if (full())
        {
            throw std::range_error("Queue full");
        }
        q.emplace(item);
        ++unfinished_tasks;
        finished.reset();
        wakeup_next(getters);
    }

    cor::task<T> get()
    {
        while (empty())
        {
            co_await getters.emplace();
        }
        co_return get_nowait();
    }
    T get_nowait()
    {
        if (empty())
        {
            throw std::range_error("Queue empty");
        }
        auto item = std::move(q.front());
        q.pop();
        wakeup_next(putters);
        return item;
    }
    cor::task<> join()
    {
        if (unfinished_tasks > 0)
        {
            co_await finished;
        }
    }
    void task_done()
    {
        if (unfinished_tasks <= 0)
        {
            throw std::runtime_error("task_done() called too many times");
        }
        --unfinished_tasks;
        if (unfinished_tasks == 0)
        {
            finished.set();
        }
    }
private:
    void wakeup_next(std::queue<Locks>& waiters)
    {
        while (not waiters.empty())
        {
            auto waiter (std::move(waiters.front()));
            waiters.pop();
            if (not waiter.is_set())
            {
                waiter.set();
                break;
            }
        }
    }

    size_t unfinished_tasks = 0;
    size_t max_size;

    Locks finished;

    cor::io_service* srvc;

    std::queue<Locks> getters;
    std::queue<Locks> putters;
    std::queue<T> q;
};
}