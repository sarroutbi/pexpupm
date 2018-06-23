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

#include <algorithm>
#include "Equation.hpp"
#include "Variable.hpp"
#include "Constant.hpp"
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

const float Equation::getValue(const side_t& side, const std::string& name) {
  float value = 0;
  for (const auto& expression : members_[side]) {
    value += expression.getValue(name);
  }
  return value;
}

void Equation::simplify(const side_t& side, const std::string& name) {
  float name_value = 0;
  for (auto& expression : members_[side]) {
    expression.simplify(name);
    name_value += expression.getValue(name);
  }

  members_[side].erase(std::remove_if(members_[side].begin(),
                                      members_[side].end(),
                                      [name](const Expression& expression){
                                   return expression.hasName(name);
                                 }),
                       members_[side].end());
  Expression exp;
  Variable var(name_value, name);
  exp.add(var);
  members_[side].push_back(exp);
}

void Equation::simplify(const side_t& side) {
  float value = 0.0f;
  std::set<std::string> expNameSet = getNameSet();
  for (auto const& name : expNameSet) {
    simplify(side, name);
  }
  for (auto& expression : members_[side]) {
    expression.simplify();
    if (expression.getValue()) {
      value += expression.getValue();
      expression.add(Constant(-1.0f * expression.getValue()));
    }
    expression.simplify();
  }
  members_[side].erase(std::remove_if(members_[side].begin(),
                                      members_[side].end(),
                                      [expNameSet](const Expression& expression){
                                        for (auto const& name : expNameSet) {
                                          if (expression.hasName(name)) {
                                            return false;
                                          }
                                        }
                                        return 0 == expression.getValue();
                                 }),
                       members_[side].end());

  if (value != 0.0f) {
    Expression exp;
    Constant constant(value);
    exp.add(constant);
    members_[side].push_back(exp);
  }
}

std::set<std::string> Equation::getNameSet() {
  std::set<std::string> nameSet;
  for (const auto& side : ALL_SIDES) {
    for (auto& expression : members_[side]) {
      for(const auto& name: expression.getNameSet()) {
        nameSet.insert(name);
      }
    }
  }
  return nameSet;
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

void Equation::apply(const std::string& name, const float& value) {
  for (const auto& side : ALL_SIDES) {
    for (auto& expression : members_[side]) {
      expression.apply(name, value);
    }
  }
}

bool Equation::equal(Equation equation) {
  auto eqNameSet = equation.getNameSet();
  auto myNameSet = getNameSet();
  if (!(eqNameSet == myNameSet)) {
    return false;
  }
  for (const auto& side : ALL_SIDES) {
    if (equation.getValue(side) != getValue(side)) {
      return false;
    }
    for (const auto& name : eqNameSet) {
      if (equation.getValue(side, name) != getValue(side, name)) {
        return false;
      }
    }
  }
  return true;
}

Equation Equation::clon() {
  Equation cloned;
  for (const auto& side : ALL_SIDES) {
    for (auto& expression : members_[side]) {
      cloned.members_[side].push_back(expression);
    }
  }
  return cloned;
}
