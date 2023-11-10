cmake_minimum_required(VERSION 3.24)
project(acm)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-O2 -DLOCAL -DDEBUG)
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,67108864")


link_libraries(-I dbg.hpp)
add_executable(main Leetcode/main.cpp)