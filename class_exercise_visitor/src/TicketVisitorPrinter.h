#ifndef __TICKET_VISITOR_PRINTER__
#define __TICKET_VISITOR_PRINTER__

class TicketVisitorPrinter : public TicketVistor
{
  virtual void VisitAddProduct(const TicketAddProduct& ticket_product);
  virtual void VisitReturn(const TicketReturn& ticket_ret);
  virtual void VisitAbort(const TicketAbort& ticket_abort);
  virtual void VisitRepeat(const TicketRepeat& ticket_rep);
}

#endif // __TICKET_VISITOR_PRINTER__
