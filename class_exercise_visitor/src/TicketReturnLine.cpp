#include "TicketReturnLine.h"

TicketReturnLine::TicketReturnLine() :
  TicketLine(-1, "Product Returned")
{

}

TicketReturnLine::~TicketReturnLine()
{

}

void TicketReturnLine::accept(TicketLineVisitor& visitor)
{
  visitor.visitTicketReturnLine(this);
}
