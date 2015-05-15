#include "Dispatcher.h"
#include "FactorialAnalyzer.h"

Dispatcher::Dispatcher()
{
  m_map["0"] = new FactorialAnalyzer();
}

Dispatcher::~Dispatcher()
{
  ;
}

int Dispatcher::dispatch(const std::string& str)
{
  std::string code(str.substr(0, 1));
  Analyzer* analyzer = m_map[code];
  m_tcp_sender.sendResult(analyzer->dispatch(str));
}
