#ifndef __PRINTER_COLOR__
#define __PRINTER_COLOR__

#include "Printer.h"

class PrinterColor : public Printer
{
public:
  PrinterColor();
  ~PrinterColor();
  virtual int getColors();
};

#endif // __PRINTER_COLOR__
