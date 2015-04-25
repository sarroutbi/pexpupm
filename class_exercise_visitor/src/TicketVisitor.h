#ifndef __TICKET_VISITOR__
#define __TICKET_VISITOR__

class TicketVisitor
{
  virtual void VisitAddProduct(const TicketAddProduct& ticket_product) = 0;
  virtual void VisitReturn(const TicketReturn& ticket_ret)  = 0;
  virtual void VisitAbort(const TicketAbort& ticket_abort) = 0;
  virtual void VisitRepeat(const TicketRepeat& ticket_rep) = 0;
}

#endif // __TICKET_VISITOR__
