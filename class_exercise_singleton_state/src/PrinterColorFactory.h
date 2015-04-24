#include "PrinterFactory.h"

class PrinterColorFactory : public PrinterFactory
{
public:
  PrinterColorFactory();
  ~PrinterColorFactory();
  virtual PrinterHandler* createObject();
};
