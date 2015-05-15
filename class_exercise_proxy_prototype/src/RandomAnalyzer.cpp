#include <assert.h>
#include <sstream>
#include "RandomAnalyzer.h"

RandomAnalyzer::RandomAnalyzer()
{
  ;
}

RandomAnalyzer::~RandomAnalyzer()
{
  ;
}

int RandomAnalyzer::dispatch(const std::string& str)
{
  assert(str.substr(0,1) == "2");
  return m_calc.random();
}

Analyzer* RandomAnalyzer::clone()
{
  return this;
}
