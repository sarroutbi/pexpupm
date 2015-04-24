#ifndef __PRINTER__
#define __PRINTER__

#include <string>

#include "PrinterHandler.h"

class PrinterHandler;

class Printer
{
public:
  static Printer* getInstance();
  void print(const std::string& text);
  void setType(const std::string& type);
private:
  Printer();
  ~Printer();
  PrinterHandler* m_handler;
  static Printer* m_printer_instancex;

};

#endif // __PRINTER__
