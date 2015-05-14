#include <assert.h>
#include <iostream>
#include "Menu.h"

int Menu::getMenuOption()
{
  bool valid_option = false;
  int option = 0;
  while (!valid_option) {
    std::cout << "1 - Add product" << std::endl;
    std::cout << "2 - Remove product" << std::endl;
    std::cout << "3 - Return product" << std::endl;
    std::cout << "4 - Repeat product" << std::endl;
    std::cout << "5 - Print Ticket" << std::endl;
    std::cout << "6 - Ticket Prize" << std::endl;
    std::cout << "7 - Print stockage" << std::endl;
    std::cout << "Insert your option:";
    std::cin >> option;
    if((option > 0) && (option <= 7)) {
      valid_option = true;
    }
  }
  return option;
}

void Menu::process()
{
  int option = 0;
  while(true) {
    option = getMenuOption();
    processOption(option);
  }
}

void Menu::processOption(const int& option)
{
  assert((option > 0) && (option <= 7));
  m_menuFacade.processOption(option);
}
