#include <fmt/core.h>
#include "nicer_syntax.hpp"
using namespace std::literals;

async<> count()
{    
    fmt::print("Uno\n");
    co_await asyncio::sleep(2s);
    fmt::print("Dos\n");
}

async<> main_c()
{
    co_await asyncio::gather(count(), count(), count());
}

int main()
{
    asyncio::run(main_c());

    return 0;
}