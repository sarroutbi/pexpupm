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

#include <math.h>
#include <cstdint>
#include <algorithm>
#include "Expression.hpp"
#include "Variable.hpp"
#include "Constant.hpp"

Expression::Expression() : termList_() {}

void Expression::add(const Term& term) {
  termList_.push_back(term.clon());
}

void Expression::add(const Expression& expression) {
  for (auto const& term : expression.termList_) {
    termList_.push_back(term->clon());
  }
}

bool Expression::empty() const {
  for (auto const& term : termList_) {
    if (term->getValue() != 0) {
      return false;
    }
  }
  return true;
}

void Expression::multiply(const float& value) {
  for (auto const& term : termList_) {
    term->multiply(value);
  }
}

float Expression::getValue() const {
  float expression_value = 0.0f;
  for (auto const& term : termList_) {
    bool isVar = false;
    for (auto const& name : getNameSet()) {
      if (term->hasName(name)) {
        isVar = true;
        break;
      }
    }
    if (!isVar) {
      expression_value += term->getValue();
    }
  }
  return expression_value * 1.0f;
}

std::set<std::string> Expression::getNameSet() const {
  std::set<std::string> nameSet;
  for (auto const& term : termList_) {
    // I dont like this cast, I prefer the option to have
    // a method to check if variable or constant, or a hasName(),
    // but it is not in the design
    Variable* var;
    if (var = dynamic_cast<Variable*>(term.get())) {
      nameSet.insert(var->getName());
    }
  }
  return nameSet;
}

float Expression::getValue(const std::string& name) const {
  float expression_value = 0.0f;
  for (auto const& term : termList_) {
    if (term->hasName(name)) {
      expression_value += term->getValue();
    }
  }
  return expression_value * 1.0f;
}

bool Expression::hasName(const std::string& name) const {
  std::set<std::string> names = getNameSet();
  return (names.find(name) != names.end());
}

bool Expression::equal(const Expression& expression) const {
  if (!compare_floats(expression.getValue(), getValue())) {
    return false;
  }
  std::set<std::string> expNameSet = expression.getNameSet();
  for (auto const& expName : expNameSet) {
    if (!compare_floats(expression.getValue(expName), getValue(expName))) {
      return false;
    }
  }
  return true;
}

bool Expression::compare_floats(float A, float B, float epsilon) const
{
  return (std::fabs(A - B) < epsilon);
}

Expression Expression::clon() const {
  Expression cloned;
  for (auto const& term : termList_) {
    cloned.add(*term.get());
  }
  return cloned;
}

std::string Expression::toString() const {
  std::string expstring;
  bool elem_added = false;

  for (auto const& term : termList_) {
    if (elem_added) {
      if (term->getValue() < 0.0f) {
        expstring += " - ";
      } else {
        expstring += " + ";
      }
    } else {
      elem_added = true;
    }
    auto no_minus = term->toString();
    no_minus.erase(0, no_minus.find_first_not_of('-'));
    expstring += no_minus;
  }
  return expstring;
}

void Expression::simplify(const std::string& name) {
  float name_value = 0.0f;
  if (!hasName(name)) {
    return;
  }
  name_value += getValue(name);
  termList_.erase(std::remove_if(termList_.begin(),
                                 termList_.end(),
                                 [name](const std::unique_ptr<Term>& term){
                                   return term->hasName(name);
                                 }),
                  termList_.end());
  add(Variable(name_value, name));
}

void Expression::simplify() {
  auto expression_constant_value = getValue();
  std::set<std::string> myNameSet = getNameSet();
  for (auto const& name : myNameSet) {
    simplify(name);
  }
  termList_.erase(std::remove_if(termList_.begin(),
                                 termList_.end(),
                                 [myNameSet](const std::unique_ptr<Term>& term){
                                   for (auto const& name : myNameSet) {
                                     if (term->hasName(name)) {
                                       return false;
                                     }
                                   }
                                   return true;
                                 }),
                  termList_.end());
  add(Constant(expression_constant_value));
}
