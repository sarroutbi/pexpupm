#include "PrinterHandler.h"
#include "PrinterColorFactory.h"
#include "PrinterColor.h"

static PrinterColorFactory bn_factory;

PrinterColorFactory::PrinterColorFactory()
{
  PrinterHandler::reg("Color", this);
}

PrinterColorFactory::~PrinterColorFactory()
{
  ;
}

PrinterHandler* PrinterColorFactory::createObject() 
{
  PrinterHandler* printerBN = new PrinterColor();
  return printerBN;
}
