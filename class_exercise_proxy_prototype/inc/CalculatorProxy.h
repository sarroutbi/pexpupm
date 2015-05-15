#ifndef CALCULATOR_PROXY_H
#define CALCULATOR_PROXY_H

#include "Calculator.h"
#include "TcpSender.h"
#include "TcpReceiver.h"

class CalculatorProxy : public Calculator {
public:
  CalculatorProxy();
  ~CalculatorProxy();
  int factorial(int fact);
  int sum(int first, int sec);
  int random();
private:
  TcpSender m_tcp_sender;
  TcpReceiver m_tcp_receiver;
};

#endif // CALCULATOR_PROXY_H
