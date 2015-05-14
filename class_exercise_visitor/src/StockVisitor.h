#ifndef __STOCK_VISITOR__
#define __STOCK_VISITOR__

#include <string>
#include "TicketLineVisitor.h"

class StockVisitor : public TicketLineVisitor
{
public:
  StockVisitor();
  ~StockVisitor();
  std::string getStock();
  virtual void visitTicketAddLine(TicketAddLine* ticket_product);
  virtual void visitTicketRemoveLine(TicketRemoveLine* ticket_product);
  virtual void visitTicketReturnLine(TicketReturnLine* ticket_ret);
  /* virtual void VisitAbort(const TicketAbort& ticket_abort); */
  /* virtual void VisitRepeat(const TicketRepeat& ticket_rep); */
private:
  int num_products;
  std::string m_stock;
};

#endif // __STOCK_VISITOR__
