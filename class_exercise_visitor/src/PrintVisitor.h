#ifndef __PRINT_VISITOR__
#define __PRINT_VISITOR__

#include <string>
#include "TicketLineVisitor.h"

class PrintVisitor : public TicketLineVisitor
{
public:
  PrintVisitor();
  ~PrintVisitor();
  std::string getLinePrintout() { return m_linePrintout; }
  virtual void visitTicketAddLine(TicketAddLine* ticket_product);
  virtual void visitTicketRemoveLine(TicketRemoveLine* ticket_product);
  virtual void visitTicketReturnLine(TicketReturnLine* ticket_ret);
  /* virtual void VisitAbort(const TicketAbort& ticket_abort); */
  /* virtual void VisitRepeat(const TicketRepeat& ticket_rep); */
private:
  std::string m_linePrintout;
};

#endif // __PRINT_VISITOR__
