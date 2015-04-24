#include <assert.h>
#include <iostream>
#include "Printer.h"

int main(void)
{
  Printer* p = Printer::getInstance();
  assert(p);
  p->setType("BN");
  p->print("Hello");
  p->setType("Color");
  p->print("Hello");
}
