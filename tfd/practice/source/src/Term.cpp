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

#include <iomanip>
#include <sstream>
#include "Term.hpp"

Term::Term() : value_(0.0) {}

Term::Term(const float& value) : value_(value) {}

const float& Term::getValue() const {
  return value_;
}

bool Term::equal(const Term & term) const {
  return term.getValue() == value_;
}

bool Term::hasName(const std::string& name) const {
  return false;
}

bool Term::hasName(const std::set<std::string>& nameList) const {
  return false;
}

std::string Term::toString() const {
  std::ostringstream oss;
  oss << value_;
  return oss.str();
}

void Term::multiply(const float& value)
{
  value_ *= value;
}
