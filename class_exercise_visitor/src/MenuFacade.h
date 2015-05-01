#ifndef __MENU_FACADE_H__
#define __MENU_FACADE_H__

#include "Ticket.h"

class MenuFacade
{
public:
  void processOption(const int& option);
private:
  void addProduct();
  void returnProduct();
  void removeProduct();
  void repeatProduct();
  void printTicket();
  void calculateTicketPrize();
  Ticket m_ticket;
};

#endif // __MENU_FACADE__
