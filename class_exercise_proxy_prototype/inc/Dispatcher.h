#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <map>
#include <string>

#include "Analyzer.h"
#include "TcpSender.h"

class TcpSender;

class Dispatcher {
  public:
    Dispatcher();
    ~Dispatcher();
    int dispatch(const std::string& string);
  private:
    TcpSender* m_tcp_sender;
    std::map<std::string, Analyzer*> m_map;
};

#endif // DISPATCHER
