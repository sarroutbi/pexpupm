#include "PrinterFactory.h"

class PrinterBNFactory : public PrinterFactory
{
public:
  PrinterBNFactory();
  ~PrinterBNFactory();
  virtual Printer* createObject();
};
