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
#include "SolutionMethod.hpp"

using equation_list_t = std::vector<Equation>;
using solution_list_t = std::unordered_map<std::string, Equation>;

class SolutionMethod;

class EquationSystem {
 public:
  EquationSystem();
  EquationSystem(const EquationSystem&) = delete;
  EquationSystem(const EquationSystem&&) = delete;
  EquationSystem& operator=(const EquationSystem&) = delete;
  ~EquationSystem() = default;
  void add(const Equation& equation);
  void set(std::unique_ptr<SolutionMethod> solution_method);
  void resolve();
  std::set<std::string> getNameSet();
  Equation get(const std::uint32_t index) const;
  Equation getLast(const std::uint32_t before) const;
  Equation getLast() const;
  void setSolution(const std::string& name, const Equation& equation);
  float getSolution(const std::string& name);
  // TODO(esergbr): add copyBefore(int) void method
  // TODO(esergbr): add copyBefore() void method
  // TODO(esergbr): add equal(EquationSystem) void method
  std::string toString() const;
 private:
  equation_list_t equationList_;
  solution_list_t solutionList_;
  std::unique_ptr<SolutionMethod> solutionMethod_;
};

#endif // __EQRESOLVER_EQUATION_SYSTEM_HPP__
