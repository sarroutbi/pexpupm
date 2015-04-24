#ifndef __PRINTER_HANDLER__
#define __PRINTER_HANDLER__

#include <string>
#include <map>

#include "PrinterFactory.h"

class PrinterFactory;

class PrinterHandler
{
public:
  static void reg(const std::string& key, PrinterFactory* factory);
  static PrinterHandler* getInstance(const std::string& key);
  virtual void print(const std::string& text) = 0;
  ~PrinterHandler();
protected:
  PrinterHandler();
};

#endif // __PRINTER_HANDLER__
