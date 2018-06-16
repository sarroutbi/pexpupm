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
#include <memory>
#include "gtest/gtest.h"
#include "Variable.hpp"
#include "Constant.hpp"

TEST(VariableTest, GivenEmptyVarWhenGetNameIsPromptedEmptyIsReturned) {
  Variable var;
  EXPECT_EQ(var.getName(), std::string());
}

TEST(VariableTest, GivenVarWithXWhenGetNameIsPromptedXIsReturned) {
  Variable var(3, "x");
  EXPECT_EQ(var.getName(), "x");
}

TEST(VariableTest, GivenEmptyVarWhenHasNameIsPromptedFalseIsReturned) {
  Variable var;
  EXPECT_EQ(var.hasName("x"), false);
}

TEST(VariableTest, GivenVarWithCertaiValueWhenHasNameIsPromptedTrueIsReturned) {
  Variable var(3, "x");
  EXPECT_EQ(var.hasName("x"), true);
}

TEST(VariableTest, GivenEmptyVarWhenToStringIsCalledEmptyIsReturned) {
  Variable var;
  EXPECT_EQ(var.toString(), std::string());
}

TEST(VariableTest,
     GivenCertainVarWithXVarAnd3ValueWhenToStringIsCalled3xIsReturned) {
  Variable var(3, "x");
  EXPECT_EQ(var.toString(), "3x");
}

TEST(TermTest, GivenATermWithCertainValueThenGetValueReturnsItProperly) {
  Term* term = std::make_unique<Constant>(3.55).get();
  EXPECT_EQ(term->getValue(), 3.55f);
}

TEST(ConstantTest,
     GivenAConstantIfTermWithThatConstantIsCheckedToBeEqualThenTrueIsReturned) {
  Constant constant(4.23f);
  EXPECT_EQ(constant.equal(Constant(4.23f)), true);
}

TEST(ConstantTest,
     GivenAConstantIfTermWithDifferentConstantIsCheckedToBeEqualThenFalseIsReturned) {
  Constant constant(0.0011f);
  EXPECT_EQ(constant.equal(Constant(0.0012f)), false);
}
