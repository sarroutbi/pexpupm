//
// Copyright 2018 sarroutbi at yahoo.es
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef __EQRESOLVER_EQUATION_SYSTEM_HPP__
#define __EQRESOLVER_EQUATION_SYSTEM_HPP__

#include <set>
#include <string>
#include <vector>
#include "Equation.hpp"

using equation_list_t = std::vector<Equation>;

class EquationSystem {
 public:
  EquationSystem();
  void add(const Equation& equation);
  // TODO(esergbr): add set(solution) void method
  // TODO(esergbr): add resolve() void method
  std::set<std::string> getNameSet();
  Equation get(const std::uint32_t index) const;
  Equation getLast(const std::uint32_t before) const;
  Equation getLast() const;
  // TODO(esergbr): add copyBefore(int) void method
  // TODO(esergbr): add copyBefore() void method
  // TODO(esergbr): add setSolution(string, Equation) void method
  // TODO(esergbr): add getSolution(string) float method
  // TODO(esergbr): add equal(EquationSystem) void method
  std::string toString() const;
  ~EquationSystem() = default;
 private:
  equation_list_t equationList_;
  equation_list_t solutionList_;
};

#endif // __EQRESOLVER_EQUATION_SYSTEM_HPP__
