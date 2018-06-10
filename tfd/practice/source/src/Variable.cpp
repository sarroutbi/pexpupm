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
#include "Variable.hpp"
#include <sstream>
#include <iomanip>

Variable::Variable() : name_(),
                       Term()
{}

Variable::Variable(const float& value, const std::string& name) :
    name_(name),
    Term(value)
{}

bool Variable::hasName(const std::string& promptname) const {
  return promptname == name_;
}

const std::string& Variable::getName() const {
  return name_;
}

const std::string Variable::toString() const {
  if(value_) {
    std::ostringstream oss;
    oss << std::setprecision(8) << std::noshowpoint << value_;
    return (oss.str() + name_);
  }
  return "";
}
