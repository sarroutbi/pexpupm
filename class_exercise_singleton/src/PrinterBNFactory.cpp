#include "Printer.h"
#include "PrinterBNFactory.h"
#include "PrinterBN.h"

static PrinterBNFactory bn_factory;

PrinterBNFactory::PrinterBNFactory()
{
  Printer::reg("BN", this);
}

PrinterBNFactory::~PrinterBNFactory()
{
  ;
}

Printer* PrinterBNFactory::createObject() 
{
  Printer* printerBN = new PrinterBN();
  return printerBN;
}
