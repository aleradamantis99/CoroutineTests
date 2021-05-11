#include <fmt/core.h>
#include "queue.hpp"
#include <cppcoro/schedule_on.hpp>
#include <cppcoro/resume_on.hpp>

#include "nicer_syntax.hpp"
#include <thread>
#include <iostream>
#include <random>
using namespace std::literals;
using TimeType = decltype (std::chrono::system_clock::now());
using Queue = asyncio::Queue<std::pair<std::string, TimeType>>;
async<std::string> makeitem()
{
    co_return fmt::format("{:02x}", std::random_device{}());
}

async<> randsleep(const std::string& caller="")
{
    int i = (rand()%10)+1;
    if (not caller.empty())
        fmt::print("{} sleeping for {} seconds.\n", caller, i);
    co_await asyncio::sleep(i);
}

async<> produce(int name, Queue& q)
{
    fmt::print("Producer iniciado: {}\n", name);
    int n = (rand()%10)+1;
    for (auto x: std::views::iota(0, n))
    {
        (void)x;
        co_await randsleep(fmt::format("Producer {}", name));
        std::string i = co_await makeitem();
        auto t = std::chrono::system_clock::now();
        co_await cor::resume_on(srvc, q.put(std::make_pair(i, t)));
        fmt::print("Producer {} added <{}> to queue.\n", name, i);
    }
}
async<> consume(int name, Queue& q)
{
    fmt::print("Consumer iniciado: {}\n", name);
    while (true)
    {
        co_await randsleep(fmt::format("Consumer {}", name));
        const auto& [i, t] = co_await cor::resume_on(srvc, q.get());
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::duration_cast<std::chrono::seconds>(now-t).count();
        fmt::print("Consumer {} got element <{}> in {} seconds.\n", name, i, time);
        q.task_done();
    }
}
/*async def main(nprod: int, ncon: int):
    q = asyncio.Queue()
    producers = [asyncio.create_task(produce(n, q)) for n in range(nprod)]
    consumers = [asyncio.create_task(consume(n, q)) for n in range(ncon)]
    await asyncio.gather(*producers)
    await q.join()  # Implicitly awaits consumers, too
    for c in consumers:
        c.cancel()*/

async<> main_c(int nprod, int ncon)
{
        fmt::print ("Everything set up\n");
    std::cout << "Hola" << std::endl;
    Queue q(srvc);
    using T = decltype(cor::schedule_on(srvc, consume(0, q)));
    std::vector<cor::task<>> producers(nprod);
    for (size_t i=0; i<producers.size(); i++)
    {
        producers[i] = produce(i, q);
    }
    std::vector<T> consumers(ncon);
    for (size_t i=0; i<consumers.size(); i++)
    {
        consumers[i] = cor::schedule_on(srvc, consume(i, q));
    }

    co_await cor::when_all(
        cor::schedule_on(srvc, cor::when_all(std::move(consumers))),
        cor::when_all(std::move(producers))
    );
}

int main(int, char* argv[])
{
    srand(444);
    auto start = chr::steady_clock::now();
    asyncio::run(main_c(argv[1][0]-'0', argv[2][0]-'0'));
    auto end = chr::steady_clock::now();
    auto duration = chr::duration_cast<chr::seconds>(end-start).count();
    fmt::print("Program finished in {} seconds.\n", duration);
    return 0;
}
