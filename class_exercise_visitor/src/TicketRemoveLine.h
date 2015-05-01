#ifndef __TICKET_REMOVE_LINE__
#define __TICKET_REMOVE_LINE__

#include "TicketLine.h"
#include "TicketLineVisitor.h"

class TicketRemoveLine : public TicketLine
{
  public:
    TicketRemoveLine();
    ~TicketRemoveLine();
    virtual void accept(TicketLineVisitor& visitor);
};

#endif // __TICKET_REMOVE_LINE__
