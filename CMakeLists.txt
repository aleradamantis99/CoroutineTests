cmake_minimum_required(VERSION 3.10)
project(CppcoroTests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

link_libraries(cppcoro pthread fmt)
add_compile_options(-fcoroutines -Wall -Wextra -pedantic)

add_executable(FirstExample main.cpp)
add_executable(JthreadExample main_jthread.cpp)
add_executable(InScheduleExample main_scheduleinside.cpp)
link_libraries(uring)
add_executable(AsyncioExample1 main_asyncio1.cpp)
add_executable(AsyncioExample2 main_asyncio2.cpp)
add_executable(AsyncioExample3 main_asyncio3.cpp)
add_executable(AsyncioExample4 main_asyncio4.cpp)
