#include "TicketAddLine.h"

TicketAddLine::TicketAddLine() : 
  TicketLine(1, "Product Added")
{
  ;
}

TicketAddLine::~TicketAddLine()
{
  ;
}

void TicketAddLine::accept(TicketLineVisitor& visitor)
{
  visitor.visitTicketAddLine(this);
}
