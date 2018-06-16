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
#include "Expression.hpp"

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

TEST(VariableTest,
     GivenCertainVarWithXVarAnd0Dot03ValueWhenToStringIsCalled3xIsReturned) {
  Variable var(0.03f, "x");
  EXPECT_EQ(var.toString(), "0.03x");
}

TEST(TermTest,
     GivenAConstantTermWithCertainValueThenGetValueReturnsItProperly) {
  Term* term = std::make_unique<Constant>(3.55).get();
  EXPECT_EQ(term->getValue(), 3.55f);
}

TEST(TermTest,
     GivenAVariableTermWithCertainValueThenGetValueReturnsItProperly) {
  Term* term = std::make_unique<Variable>(2.25f, "x").get();
  EXPECT_EQ(term->getValue(), 2.25f);
}

TEST(VariableTest,
     GivenAVariableIfTermWithDifferentValueIsCheckedEqualThenTrueIsReturned)
{
  Variable var(0.0012f, "x");
  EXPECT_EQ(var.equal(Variable(0.0012f, "x")), true);
}

TEST(VariableTest,
     GivenAVariableIfClonIsObtainedThenEqualMethodOfBothReturnsTrue) {
  Variable var(0.0011f, "y");
  EXPECT_EQ(var.equal(*var.clon().get()), true);
}

TEST(VariableTest,
     GivenAVariableWhenClonIsObtainedThenEqualMethodWithOtherVarWithSameValues\
ReturnsTrue) {
  Variable var(0.0011f, "y");
  Variable var2(0.0011f, "y");
  EXPECT_EQ(var2.equal(*var.clon().get()), true);
}

TEST(VariableTest,
     GivenAVariableIfClonIsObtainedThenEqualMethodWithOtherValueReturnsFalse) {
  Variable var(0.0011f, "x");
  Variable var2(0.0012f, "x");
  EXPECT_EQ(var2.equal(*var.clon().get()), false);
}

TEST(VariableTest,
     GivenAVariableIfClonIsObtainedThenEqualMethodWithOtherVarReturnsFalse) {
  Variable var(0.0011f, "x");
  Variable var2(0.0011f, "y");
  EXPECT_EQ(var2.equal(*var.clon().get()), false);
}

TEST(VariableTest,
     GivenAVariableIfHasNameWithSameVarIsCalledThenFalseIsReturned) {
  Variable var(0.0011f, "x");
  EXPECT_EQ(var.hasName("x"), true);
}

TEST(VariableTest,
     GivenAVariableIfHasNameWithOtherVarIsCalledThenFalseIsReturned) {
  Variable var(0.0011f, "x");
  EXPECT_EQ(var.hasName("y"), false);
}

TEST(VariableTest,
     GivenAVariableIfMultiplyIsCalledThenCorrectValueIsReturned) {
  Variable var(0.0011f, "x");
  var.multiply(3);
  EXPECT_EQ(var.getValue(), 0.0033f);
}

TEST(VariableTest,
     GivenAVariableIfMultiplyByZeroIsCalledThenCorrectValueIsReturned) {
  Variable var(0.0011f, "x");
  var.multiply(0);
  EXPECT_EQ(var.getValue(), 0.00f);
}

TEST(VariableTest,
     GivenAZeroCVariableIfMultiplyByZeroIsCalledThenCorrectValueIsReturned) {
  Variable variable(0, "z");
  variable.multiply(0);
  EXPECT_EQ(variable.getValue(), 0.00f);
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

TEST(ConstantTest,
     GivenAConstantIfClonIsObtainedThenEqualMethodOfBothReturnsTrue) {
  Constant constant(0.0011f);
  EXPECT_EQ(constant.equal(*constant.clon().get()), true);
}

TEST(ConstantTest,
     GivenAConstantIfClonIsObtainedThenEqualMethodWithDifferentReturnsFalse) {
  Constant constant(0.0011f);
  Constant constant2(0.0012f);
  EXPECT_EQ(constant2.equal(*constant.clon().get()), false);
}

TEST(ConstantTest,
     GivenAConstantIfHasNameIsCalledThenFalseIsReturned) {
  Constant constant(0.0011f);
  EXPECT_EQ(constant.hasName("x"), false);
}

TEST(ConstantTest,
     GivenAConstantIfMultiplyIsCalledThenCorrectValueIsReturned) {
  Constant constant(0.0011f);
  constant.multiply(4);
  EXPECT_EQ(constant.getValue(), 0.0044f);
}

TEST(ConstantTest,
     GivenAConstantIfMultiplyByZeroIsCalledThenCorrectValueIsReturned) {
  Constant constant(0.3f);
  constant.multiply(0);
  EXPECT_EQ(constant.getValue(), 0.00f);
}

TEST(ConstantTest,
     GivenAZeroConstantIfMultiplyByZeroIsCalledThenCorrectValueIsReturned) {
  Constant constant(0);
  constant.multiply(0);
  EXPECT_EQ(constant.getValue(), 0.00f);
}

TEST(ConstantTest,
     GivenAConstantIfToStringIsCalledThenCorrectValueIsReturned) {
  Constant constant(0.05f);
  EXPECT_EQ(constant.toString(), "0.05");
}

TEST(ExpressionTest,
     GivenAExpressionWithEmptyTermsWhenEmptyIsCalledThenTrueIsObtained) {
  Constant econstant(0);
  Variable evar(0, "x");
  Expression expression;
  expression.addTerm(econstant);
  expression.addTerm(evar);
  EXPECT_EQ(expression.empty(), true);
}

TEST(ExpressionTest,
     GivenAExpressionWithNonEmptyTermsWhenEmptyIsCalledThenFalseIsObtained) {
  Constant econstant(0);
  Variable evar(1, "z");
  Expression expression;
  expression.addTerm(econstant);
  expression.addTerm(evar);
  EXPECT_EQ(expression.empty(), false);
}

TEST(ExpressionTest,
     GivenAExpressionWithEmptyExpressionWhenEmptyIsCalledThenTrueIsObtained) {
  Constant econstant(0);
  Variable evar(0, "x");
  Expression expression;
  expression.addTerm(econstant);
  expression.addTerm(evar);
  Expression expression2;
  Variable evar2(0, "y");
  expression2.addTerm(evar2);
  expression2.addTerm(expression);
  EXPECT_EQ(expression2.empty(), true);
}
