#ifndef __TICKET_LINE_VISITOR__
#define __TICKET_LINE_VISITOR__

class TicketAddLine;

class TicketLineVisitor
{
public:
  virtual void visitTicketAddLine(TicketAddLine* ticket_product) {};
  /* virtual void visitTicketReturnLine(const TicketReturn& ticket_ret); */
  /* virtual void visitTicketAbortLine(const TicketAbort& ticket_abort); */
  /* virtual void visitTicketRepeatLine(const TicketRepeat& ticket_rep); */
protected:
  TicketLineVisitor();
  ~TicketLineVisitor();
};

#endif // __TICKET_LINE_VISITOR__
