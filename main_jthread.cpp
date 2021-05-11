#include <iostream>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/shared_task.hpp>
#include <cppcoro/task.hpp>
#include <thread>
#include <cppcoro/schedule_on.hpp>
#include <cppcoro/static_thread_pool.hpp>

namespace cor = cppcoro;

using namespace std::literals;

cor::shared_task<int> gen_task()
{
    std::cout << "Thread gen: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(2s);
    co_return 2;
}

cor::task<> waiting_thread(cor::shared_task<int>& gen, int i)
{
    std::cout << "Thread " << i << ": " << std::this_thread::get_id() << std::endl;
    int val = co_await gen;
    std::cout << "Thread " << i <<  ": " << std::this_thread::get_id() << "-" << val << std::endl;
}

int main()
{
    std::cout << "Main thread: " << std::this_thread::get_id() << std::endl;
    auto t = gen_task();
    std::jthread t1{[&] { cor::sync_wait(waiting_thread(t, 1)); std::cout << "Hilo 1 bye" << std::endl; }};
    std::jthread t2{[&] { cor::sync_wait(waiting_thread(t, 2)); std::cout << "Hilo 2 bye" << std::endl; }};


    return 0;
}