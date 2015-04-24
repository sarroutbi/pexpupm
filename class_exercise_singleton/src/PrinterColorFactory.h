#ifndef __PRINTER_COLOR_FACTORY__
#define __PRINTER_COLOR_FACTORY__

#include "PrinterFactory.h"

class PrinterColorFactory : public PrinterFactory
{
public:
  PrinterColorFactory();
  ~PrinterColorFactory();
  virtual Printer* createObject();
};

#endif // __PRINTER_COLOR_FACTORY__
