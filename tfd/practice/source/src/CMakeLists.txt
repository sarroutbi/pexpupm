cmake_minimum_required (VERSION 3.0)

add_executable(eqresolver eqresolver.cpp)
add_library(libeqresolver STATIC
  EquationSystem.cpp
  Equation.cpp
  Expression.cpp
  Variable.cpp
  Term.cpp
  Constant.cpp)
