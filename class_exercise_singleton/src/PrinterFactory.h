#ifndef __PRINTER_FACTORY__
#define __PRINTER_FACTORY__

#include "Printer.h"

class Printer;

class PrinterFactory {
 public:
  PrinterFactory();
  ~PrinterFactory();
  virtual Printer* createObject() = 0;
};

#endif // __PRINTER_FACTORY__
