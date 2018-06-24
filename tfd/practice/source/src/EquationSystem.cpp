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

#include "EquationSystem.hpp"

EquationSystem::EquationSystem() : equationList_(), solutionList_() {}

void EquationSystem::add(const Equation& equation) {
  equationList_.push_back(equation);
}

std::set<std::string> EquationSystem::getNameSet() {
  std::set<std::string> nameSet;
  for (auto & equation : equationList_) {
    auto eqNameSet = equation.getNameSet();
    nameSet.insert(eqNameSet.begin(), eqNameSet.end());
  }
  return nameSet;
}

std::string EquationSystem::toString() const {
  std::string eq_string;
  for (auto const& equation : equationList_) {
    eq_string += equation.toString();
    eq_string += "\n";
  }
  return eq_string;
}

Equation EquationSystem::get(const std::uint32_t index) const {
  if (equationList_.size() <= index) {
    return Equation();
  }
  return equationList_[index];
}

Equation EquationSystem::getLast(const std::uint32_t before) const {
  if (equationList_.size() < before) {
    return Equation();
  }
  return equationList_[before-1];
}

Equation EquationSystem::getLast() const {
  if (equationList_.empty()) {
    return Equation();
  }
  return equationList_.back();
}

