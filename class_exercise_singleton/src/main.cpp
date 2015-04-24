#include <iostream>
#include "Printer.h"

int main(void)
{
  Printer* p = Printer::getInstance("Color");
  if(p) {
    std::cout << "Colors:" << p->getColors() << std::endl;
  }
  else {
    std::cout << "Unregistered Printer" << std::endl;
  }
  delete p;
}
