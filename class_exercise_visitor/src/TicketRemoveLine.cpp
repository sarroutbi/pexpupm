#include "TicketRemoveLine.h"

TicketRemoveLine::TicketRemoveLine() : 
  TicketLine(-1, "Product Removed")
{
  ;
}

TicketRemoveLine::~TicketRemoveLine()
{
  ;
}

void TicketRemoveLine::accept(TicketLineVisitor& visitor)
{
  visitor.visitTicketRemoveLine(this);
}
