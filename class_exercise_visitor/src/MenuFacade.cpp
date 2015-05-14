#include <assert.h>
#include <iostream>
#include "MenuFacade.h"
#include "TicketAddLine.h"
#include "TicketRemoveLine.h"
#include "TicketReturnLine.h"
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
  TicketLine* line = new TicketReturnLine();
  m_ticket.addLine(line);
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
  std::cout << "\nPrize: ";
  // std::cout << m_ticket.getPrize() << std::endl;
}

void MenuFacade::calculateStock()
{
  std::cout << "\nStock: ";
  std::cout << m_ticket.getStock() << std::endl;
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
    case 7:
      calculateStock();
      break;
    default:
      assert(0);
      break;
  }
}
