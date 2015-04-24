#ifndef __PRINTER_COLOR__
#define __PRINTER_COLOR__

#include "PrinterHandler.h"

class PrinterColor : public PrinterHandler
{
public:
  PrinterColor();
  ~PrinterColor();
  virtual void print(const std::string& text);
};

#endif // __PRINTER_COLOR__
