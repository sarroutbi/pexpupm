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

#ifndef __EQRESOLVER_EXPRESSION_HPP__
#define __EQRESOLVER_EXPRESSION_HPP__

#include <memory>
#include <set>
#include <string>
#include <vector>
#include "Term.hpp"

class Expression final {
 public:
  Expression();
  Expression(const Expression& expression);
  Expression& operator=(const Expression& expression);
  bool empty() const;
  void add(const Term& term);
  void add(const Expression& expression);
  void multiply(const float& value);
  void simplify();
  void simplify(const std::string& name);
  float getValue() const;
  float getValue(const std::string& name) const;
  bool hasName(const std::string& name) const;
  std::set<std::string> getNameSet() const;
  void apply(const std::string& name, const float& value);
  bool equal(const Expression& expression) const;
  Expression clon() const;
  std::string toString() const;
 protected:
 private:
  bool compare_floats(float A, float B, float epsilon = 0.001f) const;
  std::vector<std::unique_ptr<Term>> termList_;
};

#endif //__EQRESOLVER_EXPRESSION_HPP__
