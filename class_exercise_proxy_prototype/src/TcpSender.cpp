#include "TcpSender.h"

void TcpSender::send(const std::string& str)
{
  m_tcp_recv.recv(str);
}
