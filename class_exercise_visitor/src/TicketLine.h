#ifndef __TICKET_LINE__
#define __TICKET_LINE__

#include <string>
#include "TicketLineVisitor.h"

class TicketLine
{
  public:
    TicketLine(int prize = 0,
               const std::string& description = "");
    ~TicketLine();
    std::string getDescription();
    int getPrice();
    virtual void accept(TicketLineVisitor& visitor) = 0;
  private:
    std::string m_opCode;
    int m_prize;
    std::string m_description;
};

#endif // __TICKET_LINE__
