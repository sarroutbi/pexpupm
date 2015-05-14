#ifndef __TICKET_RETURN_LINE__
#define __TICKET_RETURN_LINE__

#include "TicketLine.h"
#include "TicketLineVisitor.h"

class TicketReturnLine : public TicketLine
{
  public:
    TicketReturnLine();
    ~TicketReturnLine();
    virtual void accept(TicketLineVisitor& visitor);
};

#endif // __TICKET_RETURN_LINE__
