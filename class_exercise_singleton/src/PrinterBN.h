#ifndef __PRINTER_BN__
#define __PRINTER_BN__

#include "Printer.h"

class PrinterBN : public Printer
{
public:
  PrinterBN();
  ~PrinterBN();
  virtual int getColors();
};

#endif // __PRINTER_BN__
