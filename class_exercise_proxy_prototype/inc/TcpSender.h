#ifndef TCP_SENDER_H
#define TCP_SENDER_H

#include "TcpReceiver.h"

class TcpSender {
  public:
    void send(const std::string& str);
    void sendResult(const int& result);
  private:
    TcpReceiver m_tcp_recv;
};

#endif // TCP_SENDER
