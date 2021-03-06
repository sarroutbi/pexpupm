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
#include "Side.hpp"
#include "Equation.hpp"
#include "EquationSystem.hpp"
#include "ReductionMethod.hpp"

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
  expression.add(econstant);
  expression.add(evar);
  EXPECT_EQ(expression.empty(), true);
}

TEST(ExpressionTest,
     GivenAExpressionWithNonEmptyTermsWhenEmptyIsCalledThenFalseIsObtained) {
  Constant econstant(0);
  Variable evar(1, "z");
  Expression expression;
  expression.add(econstant);
  expression.add(evar);
  EXPECT_EQ(expression.empty(), false);
}

TEST(ExpressionTest,
     GivenAExpressionWithEmptyExpressionWhenEmptyIsCalledThenTrueIsObtained) {
  Constant econstant(0);
  Variable evar(0, "x");
  Expression expression;
  expression.add(econstant);
  expression.add(evar);
  Expression expression2;
  Variable evar2(0, "y");
  expression2.add(evar2);
  expression2.add(expression);
  EXPECT_EQ(expression2.empty(), true);
}

TEST(ExpressionTest,
     GivenAExpressionWhenMultiplyIsCalledThenCorrectValueIsObtained) {
  Variable var(1.1f, "x");
  Variable var2(2.2f, "y");
  Constant con(4.0f);
  Expression expression;
  expression.add(var);
  expression.add(var2);
  expression.add(con);
  expression.multiply(2);
  EXPECT_FLOAT_EQ(expression.getValue("x"), 2.2f);
  EXPECT_FLOAT_EQ(expression.getValue("y"), 4.4f);
  EXPECT_FLOAT_EQ(expression.getValue(), 8.0f);
}

TEST(ExpressionTest,
     GivenAExpressionWithMultipleValuesWhenGetValueIsCalled\
ThenCorrectValueIsObtained) {
  Variable var(1.1f, "x");
  Variable var2(2.2f, "x");
  Constant con(1.0f);
  Constant con2(2.0f);
  Expression expression;
  expression.add(var);
  expression.add(var2);
  expression.add(con);
  expression.add(con2);
  EXPECT_FLOAT_EQ(expression.getValue("x"), 3.3f);
  EXPECT_FLOAT_EQ(expression.getValue(), 3.0f);
}

TEST(ExpressionTest,
     GivenAExpressionWithMultipleVariablesCheckHasNameReturnsTrue) {
  Variable var(1.1f, "x");
  Variable var2(2.2f, "y");
  Expression expression;
  expression.add(var);
  expression.add(var2);
  EXPECT_EQ(expression.hasName("x"), true);
  EXPECT_EQ(expression.hasName("y"), true);
}

TEST(ExpressionTest,
     GivenAExpressionWithMultipleVariablesCheckHasNameReturnsFalse) {
  Variable var(1.1f, "x");
  Variable var2(2.2f, "y");
  Expression expression;
  EXPECT_EQ(expression.hasName("x"), false);
  EXPECT_EQ(expression.hasName("y"), false);
  expression.add(var);
  expression.add(var2);
  EXPECT_EQ(expression.hasName("z"), false);
}

TEST(ExpressionTest,
     GivenTwoEqualExpressionsWhenEqualIsCalledThenTrueIsReturned) {
  Variable var(1.1f, "x");
  Variable var2(2.2f, "y");
  Constant constant(3);
  Expression expression;
  expression.add(var);
  expression.add(var2);
  expression.add(constant);
  Variable var3(1.1f, "x");
  Variable var4(2.2f, "y");
  Constant constant2(3);
  Expression expression2;
  expression2.add(var3);
  expression2.add(var4);
  expression2.add(constant2);
  EXPECT_EQ(expression.equal(expression2), true);
}

TEST(ExpressionTest,
     GivenTwoEquivalentExpressionsWhenEqualIsCalledThenTrueIsReturned) {
  Variable var(1.1f, "x");
  Variable var2(2.2f, "x");
  Constant constant(2);
  Constant constant2(-1);
  Expression expression;
  expression.add(var);
  expression.add(var2);
  expression.add(constant);
  expression.add(constant2);
  Variable var3(3.3f, "x");
  Constant constant3(1);
  Expression expression2;
  expression2.add(var3);
  expression2.add(constant3);
  EXPECT_EQ(expression.equal(expression2), true);
}

TEST(ExpressionTest,
     GivenAExpressionWhenCloneIsObtainThenExpressionAndCloneAreEqual) {
  Variable var(1.1f, "x");
  Variable var2(2.2f, "x");
  Constant constant(2);
  Constant constant2(-1);
  Expression expression;
  expression.add(var);
  expression.add(var2);
  expression.add(constant);
  expression.add(constant2);
  Expression expression2 = expression.clon();
  EXPECT_EQ(expression.equal(expression2), true);
}

TEST(ExpressionTest,
     GivenAExpressionWithVar3xAndCons4WhenToStringIsCalledThen3xPlus4) {
  Variable var(3.0f, "x");
  Constant constant(4);
  Expression expression;
  expression.add(var);
  expression.add(constant);
  EXPECT_EQ(expression.toString(), "3x + 4");
}

TEST(ExpressionTest,
     GivenASimplifiableByVarExpressionWhenSimplifyByNameIsCalled\
ThenSimplificationIsObtained) {
  Variable var(3.0f, "x");
  Variable var2(4.0f, "x");
  Expression expression;
  expression.add(var);
  expression.add(var2);
  EXPECT_EQ(expression.toString(), "3x + 4x");
  expression.simplify("x");
  EXPECT_EQ(expression.toString(), "7x");
}

TEST(ExpressionTest,
     GivenASimplifiableByAllExpressionWhenSimplifyByNameIsCalled\
ThenSimplificationIsObtained) {
  Variable var(3.0f, "x");
  Variable var3(5.0f, "y");
  Variable var2(4.0f, "x");
  Constant con1(3);
  Constant con2(-4);
  Expression expression;
  expression.add(var);
  expression.add(var3);
  expression.add(var2);
  expression.add(con1);
  expression.add(con2);
  EXPECT_EQ(expression.toString(), "3x + 5y + 4x + 3 - 4");
  expression.simplify();
  EXPECT_EQ(expression.toString(), "7x + 5y - 1");
}

TEST(ExpressionTest,
     GivenAExpressionWithVarWhenApplyIsExecuted\
ThenCorrectValueIsObtained) {
  Variable var(3.0f, "x");
  Variable var3(5.0f, "y");
  Expression expression;
  expression.add(var);
  expression.add(var3);
  EXPECT_EQ(expression.toString(), "3x + 5y");
  expression.apply("x", 2);
  EXPECT_EQ(expression.toString(), "5y + 6");
}

TEST(EquationTest,
     GivenAEquationWithTwoTermsWithoutIndicatingSideWhenToStringIsCalledThen\
CorrectRepresentationIsObtained) {
  Variable var(4.0f, "x");
  Variable var2(5.0f, "y");
  Variable var3(3.0f, "z");
  Equation equation;
  equation.add(var);
  equation.add(var2);
  equation.add(RIGHT, var3);
  EXPECT_EQ(equation.toString(), "4x + 5y = 3z");
}

TEST(EquationTest,
     GivenAEquationWithTwoTermsInLeftWhenToStringIsCalledThen\
CorrectRepresentationIsObtained) {
  Variable var(4.0f, "x");
  Variable var2(5.0f, "y");
  Equation equation;
  equation.add(LEFT, var);
  equation.add(LEFT, var2);
  EXPECT_EQ(equation.toString(), "4x + 5y = 0");
}

TEST(EquationTest,
     GivenAEquationWhenOtherEquationIsAdded\
ThenCorrectRepresentationIsObtained) {
  Variable var(4.0f, "x");
  Variable var2(5.0f, "y");
  Constant constant1(3.0f);
  Equation equation;
  equation.add(LEFT, var);
  equation.add(LEFT, var2);
  equation.add(RIGHT, constant1);
  Variable var4(7.0f, "x");
  Constant constant2(5.0f);
  Equation equation2;
  equation2.add(RIGHT, var4);
  equation2.add(RIGHT, constant2);
  equation.add(equation2);
  EXPECT_EQ(equation.toString(), "4x + 5y = 3 + 7x + 5");
}

TEST(EquationTest,
     GivenAEquationWhenMultiplyByValueIsApplied\
ThenCorrectRepresentationIsObtained) {
  Variable var(2.0f, "x");
  Variable var2(3.0f, "y");
  Constant constant1(4.0f);
  Equation equation;
  equation.add(LEFT, var);
  equation.add(LEFT, var2);
  equation.add(LEFT, constant1);
  Variable var3(5.0f, "z");
  Equation equation2;
  equation2.add(RIGHT, var3);
  equation.add(equation2);
  EXPECT_EQ(equation.toString(), "2x + 3y + 4 = 5z");
  equation.multiply(3);
  EXPECT_EQ(equation.toString(), "6x + 9y + 12 = 15z");
}

TEST(EquationTest,
     GivenAEquationWhenGetValueOfAVariableIsExecuted\
ThenCorrectValueIsObtained) {
  Variable var(2.0f, "x");
  Variable var2(3.0f, "y");
  Constant constant1(4.0f);
  Equation equation;
  equation.add(LEFT, var);
  equation.add(LEFT, var2);
  equation.add(LEFT, constant1);
  EXPECT_EQ(equation.getValue("x"), 2);
}

TEST(EquationTest,
     GivenAEquationWhenGetValueIsExecuted\
ThenCorrectValueIsObtained) {
  Variable var(2.0f, "x");
  Variable var2(3.0f, "y");
  Constant constant1(4.0f);
  Equation equation;
  equation.add(LEFT, var);
  equation.add(LEFT, var2);
  equation.add(LEFT, constant1);
  Variable var3(5.0f, "x");
  Variable var4(6.0f, "y");
  Constant constant2(7.0f);
  equation.add(RIGHT, var3);
  equation.add(RIGHT, var4);
  equation.add(RIGHT, constant2);
  EXPECT_EQ(equation.getValue(LEFT), 4);
  EXPECT_EQ(equation.getValue(RIGHT), 7);
}

TEST(EquationTest,
     GivenAEquationWhenSimplifyIsAppliedToASideAndValue\
ThenCorrectValueIsObtained) {
  Variable var(2.0f, "x");
  Constant constant1(4.0f);
  Variable varb(3.0f, "x");
  Equation equation;
  equation.add(LEFT, var);
  equation.add(LEFT, constant1);
  equation.add(LEFT, varb);
  Variable var2(6.0f, "y");
  Constant constant2(8.0f);
  equation.add(RIGHT, var2);
  equation.add(RIGHT, constant2);
  EXPECT_EQ(equation.toString(), "2x + 4 + 3x = 6y + 8");
  equation.simplify(LEFT, "x");
  EXPECT_EQ(equation.toString(), "4 + 5x = 6y + 8");
}

TEST(EquationTest,
     GivenAEquationWhenSimplifyIsAppliedToASide\
ThenCorrectValueIsObtained) {
  Variable var(2.0f, "x");
  Variable varb(3.0f, "x");
  Constant constant1(4.0f);
  Constant constant2(3.0f);
  Equation equation;
  equation.add(LEFT, var);
  equation.add(LEFT, varb);
  equation.add(LEFT, constant1);
  equation.add(LEFT, constant2);
  Variable var2(6.0f, "y");
  Constant constant3(8.0f);
  Constant constant4(3.0f);
  equation.add(RIGHT, var2);
  equation.add(RIGHT, constant3);
  equation.add(RIGHT, constant4);
  EXPECT_EQ(equation.toString(), "2x + 3x + 4 + 3 = 6y + 8 + 3");
  equation.simplify(LEFT);
  equation.simplify(RIGHT);
  EXPECT_EQ(equation.toString(), "5x + 7 = 6y + 11");
}

TEST(EquationTest,
     GivenAEquationWithDifferentExpressionsInBothSides\
WhenApplyIsCalledThenCorrectApplicationOfValueToVarIsPerformed) {
  Variable var(4.0f, "x");
  Variable var2(5.0f, "y");
  Variable var3(3.0f, "x");
  Equation equation;
  equation.add(LEFT, var);
  equation.add(LEFT, var2);
  equation.add(RIGHT, var3);
  EXPECT_EQ(equation.toString(), "4x + 5y = 3x");
  equation.apply("x", 2);
  EXPECT_EQ(equation.toString(), "8 + 5y = 6");
  equation.apply("y", 0.5f);
  EXPECT_EQ(equation.toString(), "8 + 2.5 = 6");

}

TEST(EquationTest,
     GivenTwoEquationsWithEquivalentExpressionsInBothSides\
WhenEqualIsCalledThenTrueIsReturned) {
  Variable var(4.0f, "x");
  Variable var2(5.0f, "y");
  Constant constant1(3.0f);
  Equation equation;
  equation.add(LEFT, var);
  equation.add(LEFT, var2);
  equation.add(LEFT, constant1);
  equation.add(RIGHT, Constant(2));
  EXPECT_EQ(equation.toString(), "4x + 5y + 3 = 2");
  Equation equation2;
  equation2.add(LEFT, Constant(3));
  equation2.add(LEFT, Variable(5.0f, "y"));
  equation2.add(LEFT, Variable(4.0f, "x"));
  equation2.add(RIGHT, Constant(2));
  EXPECT_EQ(equation.equal(equation2), true);
}

TEST(EquationTest,
     GivenTwoEquationsWithUnequivalentExpressionsInBothSides\
WhenEqualIsCalledThenFalseIsReturned) {
  Equation equation;
  equation.add(RIGHT, Constant(3));
  equation.add(RIGHT, Variable(5.0f, "y"));
  equation.add(LEFT, Variable(2.0f, "x"));
  equation.add(RIGHT, Constant(5));
  Equation equation2;
  equation2.add(LEFT, Constant(3));
  equation2.add(LEFT, Variable(5.0f, "y"));
  equation2.add(LEFT, Variable(4.0f, "x"));
  equation2.add(RIGHT, Constant(2));
  EXPECT_EQ(equation2.equal(equation), false);
}

TEST(EquationTest,
     GivenAnEquationWithVariablesInBothSidesWhenClonIsExecuted\
ThenClonIsEqualToTheClonedEquation) {
  Equation equation;
  equation.add(RIGHT, Constant(3));
  equation.add(RIGHT, Variable(5.0f, "y"));
  equation.add(LEFT, Variable(2.0f, "x"));
  equation.add(RIGHT, Constant(5));
  Equation equation2 = equation.clon();
  EXPECT_EQ(equation2.equal(equation), true);
}

TEST(EquationSystemTest,
     GivenAnEquationSystemWithTwoEquationsWhenGetNameSetIsCalled\
ThenCorrectSetWithExistingVariablesNamesIsObtained) {
  Equation equation;
  equation.add(RIGHT, Constant(3));
  equation.add(RIGHT, Variable(5.0f, "y"));
  equation.add(LEFT, Variable(2.0f, "x"));
  equation.add(RIGHT, Constant(5));
  Equation equation2;
  equation2.add(RIGHT, Constant(3));
  equation2.add(RIGHT, Variable(5.0f, "y"));
  equation2.add(LEFT, Variable(2.0f, "z"));
  EquationSystem eqsystem;
  eqsystem.add(equation);
  eqsystem.add(equation2);
  auto nameSet =  eqsystem.getNameSet();
  EXPECT_NE(nameSet.find("x"), nameSet.end());
  EXPECT_NE(nameSet.find("y"), nameSet.end());
  EXPECT_NE(nameSet.find("z"), nameSet.end());
  EXPECT_EQ(nameSet.find("k"), nameSet.end());
}

TEST(EquationSystemTest,
     GivenAnEquationSystemWithThreeEquationsWhenGetOfAParticularIndexIsExecuted\
ThenCorrectEquationIsObtained) {
  Equation equation;
  equation.add(LEFT, Variable(2.0f, "x"));
  equation.add(RIGHT, Constant(5));
  Equation equation2;
  equation2.add(LEFT, Variable(5.0f, "y"));
  equation2.add(RIGHT, Constant(3));
  Equation equation3;
  equation3.add(LEFT, Variable(2.0f, "z"));
  equation3.add(RIGHT, Constant(4));
  EquationSystem eqsystem;
  eqsystem.add(equation);
  eqsystem.add(equation2);
  eqsystem.add(equation3);
  EXPECT_EQ(eqsystem.get(0).getValue("x"), 2.0f);
  EXPECT_EQ(eqsystem.get(0).getValue(RIGHT), 5.0f);
  EXPECT_EQ(eqsystem.get(0).getValue("y"), 0.0f);
  EXPECT_EQ(eqsystem.get(0).getValue("z"), 0.0f);
  EXPECT_EQ(eqsystem.get(1).getValue("y"), 5.0f);
  EXPECT_EQ(eqsystem.get(1).getValue(RIGHT), 3.0f);
  EXPECT_EQ(eqsystem.get(1).getValue("x"), 0.0f);
  EXPECT_EQ(eqsystem.get(1).getValue("z"), 0.0f);
  EXPECT_EQ(eqsystem.get(2).getValue("z"), 2.0f);
  EXPECT_EQ(eqsystem.get(2).getValue(RIGHT), 4.0f);
  EXPECT_EQ(eqsystem.get(2).getValue("x"), 0.0f);
  EXPECT_EQ(eqsystem.get(2).getValue("y"), 0.0f);
  EXPECT_EQ(eqsystem.get(3).equal(Equation()), true);
}

TEST(EquationSystemTest,
     GivenAnEquationSystemWithThreeEquationsWhenGetLastIsExecuted\
ThenCorrectEquationIsObtained) {
  Equation equation;
  equation.add(LEFT, Variable(2.0f, "x"));
  equation.add(RIGHT, Constant(5));
  Equation equation2;
  equation2.add(LEFT, Variable(5.0f, "y"));
  equation2.add(RIGHT, Constant(3));
  Equation equation3;
  equation3.add(LEFT, Variable(2.0f, "z"));
  equation3.add(RIGHT, Constant(4));
  EquationSystem eqsystem;
  eqsystem.add(equation);
  eqsystem.add(equation2);
  eqsystem.add(equation3);
  EXPECT_EQ(eqsystem.getLast().getValue("z"), 2.0f);
  EXPECT_EQ(eqsystem.getLast().getValue(RIGHT), 4.0f);
  EXPECT_EQ(eqsystem.getLast().getValue("x"), 0.0f);
  EXPECT_EQ(eqsystem.getLast().getValue("y"), 0.0f);
}

TEST(EquationSystemTest,
     GivenAnEquationSystemWithThreeEquationsWhenGetLastBeforeIndexIsExecuted\
ThenCorrectEquationIsObtained) {
  Equation equation;
  equation.add(LEFT, Variable(2.0f, "x"));
  equation.add(RIGHT, Constant(5));
  Equation equation2;
  equation2.add(LEFT, Variable(5.0f, "y"));
  equation2.add(RIGHT, Constant(3));
  Equation equation3;
  equation3.add(LEFT, Variable(2.0f, "z"));
  equation3.add(RIGHT, Constant(4));
  EquationSystem eqsystem;
  eqsystem.add(equation);
  eqsystem.add(equation2);
  eqsystem.add(equation3);
  EXPECT_EQ(eqsystem.getLast(2).getValue("y"), 5.0f);
  EXPECT_EQ(eqsystem.getLast(2).getValue(RIGHT), 3.0f);
  EXPECT_EQ(eqsystem.getLast(2).getValue("x"), 0.0f);
  EXPECT_EQ(eqsystem.getLast(2).getValue("z"), 0.0f);
}

TEST(EquationSystemTest,
     GivenAnEquationSystemWithTwoEquationsWhenToStringIsExecuted\
ThenCorrectStringRepresentingBothEquationsIsObtained) {
  Equation equation;
  equation.add(LEFT, Variable(2.0f, "x"));
  equation.add(LEFT, Variable(3.0f, "y"));
  equation.add(RIGHT, Constant(5));
  Equation equation2;
  equation2.add(LEFT, Variable(5.0f, "y"));
  equation2.add(RIGHT, Constant(3));
  equation2.add(RIGHT, Variable(4.0f, "x"));
  EquationSystem eqsystem;
  eqsystem.add(equation);
  eqsystem.add(equation2);
  EXPECT_EQ(eqsystem.toString(), "2x + 3y = 5\n5y = 3 + 4x\n");
}

TEST(EquationSystemTest,
     GivenAnEquationSystemWithTwoEquationsAndResolutionMethodWhenResolveIsCalled\
ThenCorrectSolutionIsObtained) {
  Equation equation;
  equation.add(LEFT, Variable(2.0f, "x"));
  equation.add(LEFT, Variable(1.0f, "y"));
  equation.add(RIGHT, Constant(4));
  Equation equation2;
  equation2.add(LEFT, Variable(1.0f, "x"));
  equation2.add(LEFT, Variable(3.0f, "y"));
  equation2.add(RIGHT, Constant(7));
  EquationSystem eqsystem;
  eqsystem.add(equation);
  eqsystem.add(equation2);
  eqsystem.set(std::make_unique<ReductionMethod>());
  eqsystem.resolve();
  // TODO: This test case should pass
  // when resolve method of ReductionMethod is implemented
  EXPECT_EQ(eqsystem.getSolution("x"), 1.0f);
  EXPECT_EQ(eqsystem.getSolution("y"), 2.0f);
}
