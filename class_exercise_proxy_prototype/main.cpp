#include "Calculator.h"
#include "CalculatorReal.h"
#include "CalculatorProxy.h"
#include <sstream>
#include <iostream>

int dump_operations(Calculator* real) 
{
  std::stringstream ss;
  ss << "Fact  (5):" << real->factorial(5) << std::endl;
  ss << "Sum (2+3):" << real->sum(2, 3) << std::endl;
  ss << "Rand     :" << real->random() << std::endl;
  std::cout << ss.str();
}

int main(void)
{
  Calculator* calc_real = new CalculatorReal();
  dump_operations(calc_real);

  Calculator* calc_proxy = new CalculatorProxy();
  dump_operations(calc_proxy);
}
