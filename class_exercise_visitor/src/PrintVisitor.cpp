#include <assert.h>
#include <sstream>
#include "PrintVisitor.h"
#include "TicketAddLine.h"

PrintVisitor::PrintVisitor()
{
  ;
}

PrintVisitor::~PrintVisitor()
{
  ;
}

void PrintVisitor::visitTicketAddLine(TicketAddLine* ticket_product)
{
  assert(ticket_product);
  std::stringstream ss;
  ss << "A: " << ticket_product->getDescription()
     << " Price: " << ticket_product->getPrice();
  m_linePrintout += ss.str();
  m_linePrintout += '\n';
}
