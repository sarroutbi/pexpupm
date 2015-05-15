#ifndef FACTORIAL_ANALYZER_H
#define FACTORIAL_ANALYZER_H

#include "Analyzer.h"

class FactorialAnalyzer : public Analyzer {
  public:
    FactorialAnalyzer();
    ~FactorialAnalyzer();
    virtual int dispatch(const std::string& string);
    virtual Analyzer* clone();
};

#endif // FACTORIAL_ANALYZER_H
