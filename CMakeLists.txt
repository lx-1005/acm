cmake_minimum_required(VERSION 3.24)
project(acm)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-DLOCAL -DDEBUG) # 本地调试

add_compile_options(-O2)
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,67108864")
#add_compile_options(-Wconversion -Wduplicated-cond
#                    -fsanitize=address -fsanitize=undefined -fsanitize=undefined -fno-sanitize-recover)

add_executable(main main.cpp dbg.hpp)


#add_executable(cf_a Codeforces/a.cpp dbg.hpp)
#add_executable(cf_b Codeforces/b.cpp dbg.hpp)
#add_executable(cf_c Codeforces/c.cpp dbg.hpp)
#add_executable(cf_d Codeforces/d.cpp dbg.hpp)
#add_executable(cf_e Codeforces/e.cpp dbg.hpp)
#add_executable(cf_f Codeforces/f.cpp dbg.hpp)
add_executable(LCA algorithm_template/数据结构/二叉树/LCA.cpp)