cmake_minimum_required(VERSION 3.24)
project(acm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-Wall,-Wextra,-Wl,-no_warn_duplicate_libraries-ld_classic,--stack,67108864")
set(CMAKE_CXX_FLAGS "-O3 -DLOCAL")


link_libraries(-I dbg.hpp)