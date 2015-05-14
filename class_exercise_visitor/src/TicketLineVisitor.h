#ifndef __TICKET_LINE_VISITOR__
#define __TICKET_LINE_VISITOR__

class TicketAddLine;
class TicketRemoveLine;
class TicketReturnLine;

class TicketLineVisitor
{
public:
  virtual void visitTicketAddLine(TicketAddLine* ticket_product) {};
  virtual void visitTicketRemoveLine(TicketRemoveLine* ticket_abort) {};
  virtual void visitTicketReturnLine(TicketReturnLine* ticket_ret) {};
  /* virtual void visitTicketRepeatLine(const TicketRepeat& ticket_rep); */
protected:
  TicketLineVisitor();
  ~TicketLineVisitor();
};

#endif // __TICKET_LINE_VISITOR__
