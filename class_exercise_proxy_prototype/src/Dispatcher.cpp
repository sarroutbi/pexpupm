#include "Dispatcher.h"
#include "FactorialAnalyzer.h"

Dispatcher::Dispatcher(TcpReceiver* recv) : m_tcp_sender()
{
  m_map["0"] = new FactorialAnalyzer();
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
