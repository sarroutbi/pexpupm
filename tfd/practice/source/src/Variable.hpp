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
#ifndef __EQRESOLVER_VARIABLE_HPP__
#define __EQRESOLVER_VARIABLE_HPP__
#include <set>
#include <string>
#include "Term.hpp"

class Variable final : public Term {
 public:
  Variable();
  Variable(const float& value, const std::string& name);
  bool hasName(const std::string& name) const override;
  bool hasName(const std::set<std::string>& nameList) const override;
  const std::string& getName() const;
  std::string toString() const override;
  bool equal(const Term& term) const override;
  std::unique_ptr<Term> clon() const;
  void dispatch(/*TODO TERM VISITOR*/) const override;
 private:
  std::string name_;
};

#endif // __EQRESOLVER_VARIABLE_HPP__
