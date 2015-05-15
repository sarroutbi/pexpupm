#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <map>
#include <string>

#include "Analyzer.h"
#include "TcpSender.h"

class TcpSender;
class TcpReceiver;

class Dispatcher {
  public:
    Dispatcher(TcpReceiver* recv);
    ~Dispatcher();
    int dispatch(const std::string& string);
    void setRecv(TcpReceiver* recv);
  private:
    Dispatcher();
    TcpSender* m_tcp_sender;
    std::map<std::string, Analyzer*> m_map;
};

#endif // DISPATCHER
