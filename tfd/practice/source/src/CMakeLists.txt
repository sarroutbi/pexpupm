cmake_minimum_required (VERSION 3.0)

add_executable(eqresolver eqresolver.cpp)
add_library(libeqresolver STATIC
  Variable.cpp
  Term.cpp)
