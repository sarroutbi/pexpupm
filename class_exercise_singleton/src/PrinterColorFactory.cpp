#include "Printer.h"
#include "PrinterColorFactory.h"
#include "PrinterColor.h"

static PrinterColorFactory bn_factory;

PrinterColorFactory::PrinterColorFactory()
{
  Printer::reg("Color", this);
}

PrinterColorFactory::~PrinterColorFactory()
{
  ;
}

Printer* PrinterColorFactory::createObject() 
{
  Printer* printerColor = new PrinterColor();
  return printerColor;
}
