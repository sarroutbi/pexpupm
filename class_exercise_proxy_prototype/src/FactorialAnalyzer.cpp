#include <assert.h>
#include <sstream>
#include "FactorialAnalyzer.h"

FactorialAnalyzer::FactorialAnalyzer()
{
  ;
}

FactorialAnalyzer::~FactorialAnalyzer()
{
  ;
}

int FactorialAnalyzer::dispatch(const std::string& str)
{
  std::stringstream ss;
  int oper;
  assert(str.substr(0,1) == "0");
  ss << str.substr(2,1);
  ss >> oper;
  return m_calc.factorial(oper);
}

Analyzer* FactorialAnalyzer::clone()
{
  return this;
}

