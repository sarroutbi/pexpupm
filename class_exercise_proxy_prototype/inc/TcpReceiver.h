#ifndef TCP_RECEIVER_H
#define TCP_RECEIVER_H

#include <string>
#include "Dispatcher.h"

class TcpReceiver {
  public:
    void recv(const std::string& str);
    void recvResult(const int& result);
  private:
    Dispatcher m_dispatcher;
};

#endif // TCP_RECEIVER
