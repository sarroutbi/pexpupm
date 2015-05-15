#ifndef ANALYZER_H
#define ANALYZER_H

#include "CalculatorReal.h"

class Analyzer {
  public:
    virtual int dispatch(const std::string& str) = 0;
    virtual Analyzer* clone() = 0;
  protected:
    CalculatorReal m_calc;
};

#endif // ANALYZER_H
