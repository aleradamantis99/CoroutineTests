#include <fmt/core.h>
#include <fmt/color.h>

#include "nicer_syntax.hpp"
using namespace std::literals;
auto c = std::to_array({
    fg(fmt::color::floral_white),  
    fg(fmt::color::crimson),
    fg(fmt::color::steel_blue)
});

async<int> make_random(int idx, int threshold = 6)
{    
    fmt::print(c[idx], "Initiated makerandom({}).\n", idx);
    auto gen = [] { return (rand()%10)+1; };
    int i =gen();
    while (i <= threshold)
    {
        fmt::print(c[idx], "makerandom({}) == {} too low; retrying.\n", idx, i);
        co_await asyncio::sleep(idx+i);
        i = gen();
    }
    fmt::print(c[idx], "Finished: makerandom({}) == {}\n", idx, i);
    co_return i;

}

async<std::tuple<int, int, int>> main_c()
{
    co_return co_await asyncio::gather(make_random(0, 8), make_random(1, 7), make_random(2, 6));
}

int main()
{
    srand(444);
    const auto& [a, b, c] = asyncio::run(main_c());
    fmt::print("r1: {} r2: {} r3: {}\n", a, b, c);
    return 0;
}