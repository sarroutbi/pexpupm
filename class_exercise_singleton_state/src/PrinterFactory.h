#ifndef __PRINTER_FACTORY__
#define __PRINTER_FACTORY__

#include "PrinterHandler.h"

class PrinterHandler;

class PrinterFactory {
 public:
  virtual PrinterHandler* createObject() = 0;
};

#endif // __PRINTER_FACTORY__
