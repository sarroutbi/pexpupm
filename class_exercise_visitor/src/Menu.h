#ifndef __MENU_H__
#define __MENU_H__

#include "MenuFacade.h"

class Menu
{
public:
  void process();
private:
  int  getMenuOption();
  void processOption(const int& option);
  MenuFacade m_menuFacade;
};

#endif // __MENU_H__
