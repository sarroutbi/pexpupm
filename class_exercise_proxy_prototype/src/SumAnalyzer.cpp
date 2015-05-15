#include <assert.h>
#include <sstream>
#include "SumAnalyzer.h"

SumAnalyzer::SumAnalyzer()
{
  ;
}

SumAnalyzer::~SumAnalyzer()
{
  ;
}

int SumAnalyzer::dispatch(const std::string& str)
{
  std::stringstream ss;
  int oper1;
  int oper2;
  assert(str.substr(0,1) == "1");
  ss << str.substr(2,1);
  ss >> oper1;
  ss.clear();
  ss << str.substr(4,1);
  ss >> oper2;
  return m_calc.sum(oper1, oper2);
}

Analyzer* SumAnalyzer::clone()
{
  return this;
}

