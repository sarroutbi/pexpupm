#ifndef SUM_ANALYZER_H
#define SUM_ANALYZER_H

#include "Analyzer.h"

class SumAnalyzer : public Analyzer {
  public:
    SumAnalyzer();
    ~SumAnalyzer();
    virtual int dispatch(const std::string& string);
    virtual Analyzer* clone();
};

#endif // SUM_ANALYZER_H
