#include <assert.h>
#include "TcpSender.h"

TcpSender::TcpSender() : m_tcp_recv(NULL)
{
  ;
}

void TcpSender::setRecv(TcpReceiver* recv)
{
  assert(recv);
  m_tcp_recv = recv;
}

void TcpSender::send(const std::string& str)
{
  m_tcp_recv->recv(str);
}

void TcpSender::sendResult(const int& res)
{
  m_tcp_recv->recvResult(res);
}

TcpSender::~TcpSender()
{
  ;
}
