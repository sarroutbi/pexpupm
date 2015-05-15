#ifndef TCP_RECEIVER_H
#define TCP_RECEIVER_H

#include <string>
#include "Dispatcher.h"
#include "TcpSender.h"

class TcpSender;
class Dispatcher;

class TcpReceiver {
  public:
    TcpReceiver();
    ~TcpReceiver();
    void recv(const std::string& str);
    void recvResult(const int& result) { m_last_result = result; }
    int getLastResult () { return m_last_result; }
  private:
    Dispatcher* m_dispatcher;
    int m_last_result;
};

#endif // TCP_RECEIVER
