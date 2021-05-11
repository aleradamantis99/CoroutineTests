#include <fmt/core.h>
#include "nicer_syntax.hpp"
using namespace std::literals;

async<std::string> part1(int n)
{    
    const auto gen = [] { return (rand()%9)+1; };
    int i = gen();
    
    fmt::print("part1({}) sleeping for {} seconds.\n", n, i);
    co_await asyncio::sleep(i);

    std::string result = fmt::format("result{}-1", n);
    fmt::print("Returning part1({}) == {}.\n", n, result);
    co_return result;
}
async<std::string> part2(int n, const std::string& arg)
{
    const auto gen = [] { return (rand()%9)+1; };
    int i = gen();

    fmt::print("part2({} {}) sleeping for {} seconds.\n", n, arg, i);
    co_await asyncio::sleep(i);

    std::string result = fmt::format("result{}-2 derived from {}", n, arg);
    fmt::print("Returning part2({} {}) == {}.\n", n, arg, result);
    co_return result;
}
async<> chain(int n)
{
    auto start = chr::steady_clock::now();
    std::string p1 = co_await part1(n);
    std::string p2 = co_await part2(n, p1);
    auto end = chr::steady_clock::now();
    auto duration = chr::duration_cast<chr::seconds>(end-start).count();
    fmt::print("-->Chained result{} => {} (took {} seconds).\n", n, p2, duration);

}

template <typename... Args>
async<> main_c(Args&&... args)
{
    co_await asyncio::gather(chain(std::forward<Args>(args))...);
}

int main()
{
    srand(444);
    auto start = chr::steady_clock::now();
    asyncio::run(main_c(9, 6, 3));
    auto end = chr::steady_clock::now();
    auto duration = chr::duration_cast<chr::seconds>(end-start).count();
    fmt::print("Program finished in {} seconds.\n", duration);
    return 0;
}
