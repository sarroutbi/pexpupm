#include "TcpReceiver.h"

TcpReceiver::TcpReceiver() : 
  m_dispatcher(NULL), m_sender(NULL), last_result(0)
{
  m_dispatcher = new Dispatcher();
}

void TcpReceiver::recv(const std::string& str)
{
  m_dispatcher->dispatch(str);
}

void TcpReceiver::recvResult(const int& res)
{
  last_result = res;
}

TcpReceiver::~TcpReceiver()
{
  ;
}
