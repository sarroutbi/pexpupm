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

#include "Equation.hpp"
#include "Side.hpp"

Equation::Equation() : members_() {}

void Equation::add(const Term& term) {
  Expression exp;
  exp.add(term);
  members_[DEFAULT_SIDE].push_back(exp);
}

void Equation::add(const side_t& side, const Term& term) {
  Expression exp;
  exp.add(term);
  members_[side].push_back(exp);
}

void Equation::add(Equation equation) {
  for (const auto& side : ALL_SIDES) {
    for (const auto& expression : equation.members_[side]) {
      members_[side].push_back(expression);
    }
  }
}

void Equation::multiply(const float value) {
  for (const auto& side : ALL_SIDES) {
    for (auto& expression : members_[side]) {
      expression.multiply(value);
    }
  }
}

const float Equation::getValue(const std::string& name) {
  float value = 0;
  for (const auto& expression : members_[LEFT]) {
    value += expression.getValue(name);
  }
  return value;
}

const float Equation::getValue(const side_t& side) {
  float value = 0;
  for (const auto& expression : members_[side]) {
    value += expression.getValue();
  }
  return value;
}

std::string Equation::toString() const {
  std::string equation;
  auto left = members_.find(LEFT);
  if (left != members_.end()) {
    bool elem_added = false;
    for (auto const& elem : left->second) {
      if (elem_added) {
        equation += " + ";
      } else {
        elem_added = true;
      }
      equation += elem.toString();
    }
  } else {
    equation += "0";
  }
  equation += " = ";
  auto right = members_.find(RIGHT);
  if (right != members_.end()) {
    bool elem_added = false;
    for (auto const& elem : right->second) {
      if (elem_added) {
        equation += " + ";
      } else {
        elem_added = true;
      }
      equation += elem.toString();
    }
  } else {
    equation += "0";
  }
  return equation;
}
