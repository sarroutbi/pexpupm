#ifndef __PRINTER__
#define __PRINTER__

#include <string>
#include <map>

#include "PrinterFactory.h"

class PrinterFactory;

class Printer
{
public:
  static void reg(const std::string& key, PrinterFactory* factory);
  static Printer* getInstance(const std::string& key);
  virtual int getColors() = 0;
  ~Printer();
protected:
  Printer(int colors = 0);
  int m_colors;
};

#endif // __PRINTER__
