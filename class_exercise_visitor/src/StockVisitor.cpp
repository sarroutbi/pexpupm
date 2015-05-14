#include <assert.h>
#include <sstream>
#include "StockVisitor.h"
#include "TicketAddLine.h"
#include "TicketRemoveLine.h"
#include "TicketReturnLine.h"

StockVisitor::StockVisitor() : num_products(10)
{
  ;
}

StockVisitor::~StockVisitor()
{
  ;
}

std::string StockVisitor::getStock()
{
  std::stringstream ss;

  ss << "Members left:" << num_products << std::endl;

  return ss.str();
}

void StockVisitor::visitTicketAddLine(TicketAddLine* ticket_product)
{
  assert(ticket_product);
  num_products --;
}

void StockVisitor::visitTicketRemoveLine(TicketRemoveLine* ticket_product)
{
  assert(ticket_product);
  num_products ++;
}

void StockVisitor::visitTicketReturnLine(TicketReturnLine* ticket_product)
{
  assert(ticket_product);
  num_products ++;
}
