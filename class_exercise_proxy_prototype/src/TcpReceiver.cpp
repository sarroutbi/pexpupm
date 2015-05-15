#include "TcpReceiver.h"

void TcpReceiver::recv(const std::string& str)
{
  m_dispatcher.dispatch(str);
}
