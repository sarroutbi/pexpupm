#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
  virtual int factorial(int fact) = 0;
  virtual int sum(int first, int second) = 0;
  virtual int random() = 0;
};

#endif // CALCULATOR_PROXY_H
