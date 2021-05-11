#include <iostream>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/when_all.hpp>
#include <cppcoro/shared_task.hpp>
#include <cppcoro/task.hpp>
#include <thread>
#include <cppcoro/schedule_on.hpp>
#include <cppcoro/resume_on.hpp>
#include <cppcoro/static_thread_pool.hpp>

namespace cor = cppcoro;

using namespace std::literals;

cor::shared_task<int> gen_task()
{
    std::cout << "Thread gen: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(2s);
    co_return 2;
}
cor::task<> waiting_thread(cor::shared_task<int>& gen, cor::static_thread_pool& p)
{    
    std::cout << "Thread: " << std::this_thread::get_id() << std::endl;
    co_await p.schedule();
    std::cout << "Thread: " << std::this_thread::get_id() << std::endl;
    int val = co_await cor::resume_on(p, gen);
    std::cout << "Thread: " << std::this_thread::get_id() << "-" << val << std::endl;
}

int main()
{
    cor::static_thread_pool pool(4);
    std::cout << "Número de hilos: " << std::thread::hardware_concurrency() << '\n';
    std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
    auto t = gen_task();
    cor::sync_wait(
        cor::when_all(
            waiting_thread(t, pool), 
            waiting_thread(t, pool)
        )
    );


    return 0;
}