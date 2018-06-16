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
#ifndef __EQRESOLVER_TERM_HPP__
#define __EQRESOLVER_TERM_HPP__

#include <set>
#include <string>

class Term {
 public:
  Term();
  explicit Term(const float& value);
  const float& getValue() const;
  void multiply(const float& value);
  virtual bool hasName(const std::string& name) const;
  virtual bool hasName(const std::set<std::string>& nameList) const;
  virtual bool equal(const Term & term) const;
  virtual std::string toString() const;
  // virtual Term clon() const = 0;
  // virtual void dispatch( /*TODO TERM VISITOR*/) const = 0;
 protected:
  float value_;
  static auto constexpr FLOAT_PRECISION = 8;
 private:
};

#endif // __EQRESOLVER_TERM_HPP__

