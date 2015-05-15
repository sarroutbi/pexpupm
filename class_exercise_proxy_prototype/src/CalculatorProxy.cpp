#include <stdlib.h>
#include <assert.h>
#include <sstream>
#include "CalculatorProxy.h"

CalculatorProxy::CalculatorProxy() : m_tcp_sender(), m_tcp_receiver()
{
  m_tcp_sender.setRecv(&m_tcp_receiver);
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
  return m_tcp_receiver.getLastResult();
}

int CalculatorProxy::sum(int oper1, int oper2)
{
  std::stringstream ss;
  ss << "1" << ";" << oper1 << ";" << oper2;
  m_tcp_sender.send(ss.str());
  return m_tcp_receiver.getLastResult();
}

int CalculatorProxy::random()
{
  std::stringstream ss;
  ss << "2";
  m_tcp_sender.send(ss.str());
  return m_tcp_receiver.getLastResult();
}
