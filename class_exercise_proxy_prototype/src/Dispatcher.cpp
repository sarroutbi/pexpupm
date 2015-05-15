#include "Dispatcher.h"
#include "FactorialAnalyzer.h"
#include "SumAnalyzer.h"
#include "RandomAnalyzer.h"

Dispatcher::Dispatcher(TcpReceiver* recv) : m_tcp_sender()
{
  m_map["0"] = new FactorialAnalyzer();
  m_map["1"] = new SumAnalyzer();
  m_map["2"] = new RandomAnalyzer();
  m_tcp_sender = new TcpSender();
  m_tcp_sender->setRecv(recv);
}

void Dispatcher::setRecv(TcpReceiver* recv)
{
  m_tcp_sender->setRecv(recv);
}

Dispatcher::~Dispatcher()
{
  std::map<std::string, Analyzer*>::const_iterator it;
  for (it = m_map.begin(); it != m_map.end(); it++) {
    delete it->second;
  }
  delete m_tcp_sender;
}

int Dispatcher::dispatch(const std::string& str)
{
  std::string code(str.substr(0, 1));
  Analyzer* analyzer = m_map[code]->clone();
  m_tcp_sender->sendResult(analyzer->dispatch(str));
}
