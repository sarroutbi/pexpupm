#ifndef TCP_SENDER_H
#define TCP_SENDER_H

#include <string>
#include "TcpReceiver.h"

class TcpReceiver;

class TcpSender {
  public:
    TcpSender();
    ~TcpSender();
    void setRecv(TcpReceiver* recv);
    void send(const std::string& str);
    void sendResult(const int& result);
    void assocRec(TcpReceiver* rec);
  private:
    TcpReceiver* m_tcp_recv;
};

#endif // TCP_SENDER
