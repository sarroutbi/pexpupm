#ifndef CALCULATOR_REAL_H
#define CALCULATOR_REAL_H

#include "Calculator.h"

class CalculatorReal : public Calculator {
public:
  CalculatorReal();
  ~CalculatorReal();
  virtual int factorial(int fact);
  virtual int sum(int oper1, int oper2);
  virtual int random();
};

#endif // CALCULATOR_REAL_H
