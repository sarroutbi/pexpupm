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

#ifndef __EQRESOLVER_EQUATION_HPP__
#define __EQRESOLVER_EQUATION_HPP__

#include <string>
#include <unordered_map>
#include <vector>
#include "Expression.hpp"
#include "Side.hpp"

using exp_list_t =  std::vector<Expression>;
using side_t = std::uint8_t;
using members_t = std::unordered_map<side_t, exp_list_t>;
class Equation {
 public:
  Equation();
  void add(const side_t& side, const Term& term);
  // TODO(esergbr): Many methods here pending
  std::string toString() const;
 private:
  members_t members_;
};

#endif // __EQRESOLVER_EQUATION_HPP__
