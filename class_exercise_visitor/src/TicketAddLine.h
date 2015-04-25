#ifndef __TICKET_ADD_LINE__
#define __TICKET_ADD_LINE__

#include "TicketLine.h"
#include "TicketLineVisitor.h"

class TicketAddLine : public TicketLine
{
  public:
    TicketAddLine();
    ~TicketAddLine();
    virtual void accept(TicketLineVisitor& visitor);
};

#endif // __TICKET_ADD_LINE__
