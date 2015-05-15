#ifndef RANDOM_ANALYZER_H
#define RANDOM_ANALYZER_H

#include "Analyzer.h"

class RandomAnalyzer : public Analyzer {
  public:
    RandomAnalyzer();
    ~RandomAnalyzer();
    virtual int dispatch(const std::string& string);
    virtual Analyzer* clone();
};

#endif // RANDOM_ANALYZER_H
