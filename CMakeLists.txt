cmake_minimum_required(VERSION 3.24)
project(acm)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-DFILEIO -D__APPLE__)
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,67108864")
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")


link_libraries(-I dbg.hpp)

add_executable(A "Codeforces/1797(div2)/A.cpp")

include_directories(SYSTEM "/usr/local/include")
