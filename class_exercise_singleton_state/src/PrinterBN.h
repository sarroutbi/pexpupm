#ifndef __PRINTER_BN__
#define __PRINTER_BN__

#include "PrinterHandler.h"

class PrinterBN : public PrinterHandler
{
public:
  PrinterBN();
  ~PrinterBN();
  virtual void print(const std::string& text);
};

#endif // __PRINTER_BN__
