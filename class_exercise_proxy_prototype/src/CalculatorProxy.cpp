#include <stdlib.h>
#include <assert.h>
#include <sstream>
#include "CalculatorProxy.h"

CalculatorProxy::CalculatorProxy()
{
  ;
}

CalculatorProxy::~CalculatorProxy()
{
  ;
}

int CalculatorProxy::factorial(int fact)
{
  std::stringstream ss;
  ss << "0" << ";" << fact;
  m_tcp_sender.send(ss.str());
}

int CalculatorProxy::sum(int oper1, int oper2)
{
  std::stringstream ss;
  ss << "1" << ";" << oper1 << ";" << oper2;
  m_tcp_sender.send(ss.str());
}

int CalculatorProxy::random()
{
  std::stringstream ss;
  ss << "0";
  m_tcp_sender.send(ss.str());
}
