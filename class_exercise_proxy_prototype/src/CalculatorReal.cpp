#include <stdlib.h>
#include <assert.h>
#include "CalculatorReal.h"

CalculatorReal::CalculatorReal()
{

}

CalculatorReal::~CalculatorReal()
{

}

int CalculatorReal::factorial(int fact)
{
  assert(fact > 0);
  int calc = fact;
  if (calc<=1)
    return(1);
  else {
    calc = calc * factorial(calc-1);
    return calc;
  }
}

int CalculatorReal::sum(int oper1, int oper2)
{
  return oper1 + oper2;
}

int CalculatorReal::random()
{
  return rand();
}
