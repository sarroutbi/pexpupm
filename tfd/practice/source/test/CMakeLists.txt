cmake_minimum_required (VERSION 3.0)

add_executable(testeqresolver testeqresolver.cpp)
target_link_libraries(testeqresolver libeqresolver gtest gtest_main pthread)
