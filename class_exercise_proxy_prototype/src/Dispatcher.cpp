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
  //PENDING: DELETE all mmap analyzers;
  
  delete m_tcp_sender;
}

int Dispatcher::dispatch(const std::string& str)
{
  std::string code(str.substr(0, 1));
  Analyzer* analyzer = m_map[code];
  m_tcp_sender->sendResult(analyzer->dispatch(str));
}
