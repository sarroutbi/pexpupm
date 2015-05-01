#include <assert.h>
#include <iostream>
#include "MenuFacade.h"
#include "TicketAddLine.h"
#include "TicketRemoveLine.h"
#include "PrintVisitor.h"

void MenuFacade::addProduct()
{
  TicketLine* line = new TicketAddLine();
  m_ticket.addLine(line);
}

void MenuFacade::removeProduct()
{
  TicketLine* line = new TicketRemoveLine();
  m_ticket.addLine(line);
}

void MenuFacade::returnProduct()
{
  ;
}

void MenuFacade::repeatProduct()
{
  ;
}

void MenuFacade::printTicket()
{
  std::cout << "\n======= Ticket ========" << std::endl;
  std::cout << m_ticket.getPrintout();
  std::cout << "==== End of Ticket ====\n" << std::endl;
}

void MenuFacade::calculateTicketPrize()
{
  ;
}

void MenuFacade::processOption(const int& option)
{
  switch (option)
  {
    case 1:
      addProduct();
      break;
    case 2:
      removeProduct();
      break;
    case 3:
      returnProduct();
      break;
    case 4:
      repeatProduct();
      break;
    case 5:
      printTicket();
      break;
    case 6:
      calculateTicketPrize();
      break;
    default:
      assert(0);
      break;
  }
}
