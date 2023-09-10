cmake_minimum_required(VERSION 3.24)
project(acm)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-O2 -DLOCAL -DDEBUG)
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,67108864")

link_libraries(-I dbg.hpp)
add_executable(main main.cpp)
add_executable(A "Codeforces/1822(div3)/A.cpp")
add_executable(B "Codeforces/1822(div3)/B.cpp")
add_executable(C "Codeforces/1822(div3)/C.cpp")
add_executable(D "Codeforces/1822(div3)/D.cpp")
add_executable(E "Codeforces/1822(div3)/E.cpp")