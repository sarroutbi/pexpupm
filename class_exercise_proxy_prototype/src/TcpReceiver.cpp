#include "TcpReceiver.h"

TcpReceiver::TcpReceiver() : m_dispatcher(NULL), m_last_result(0)
{
  m_dispatcher = new Dispatcher(this);
}

void TcpReceiver::recv(const std::string& str)
{
  m_dispatcher->dispatch(str);
}

TcpReceiver::~TcpReceiver()
{
  delete m_dispatcher;
}
