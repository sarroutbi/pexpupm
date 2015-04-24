#include "PrinterHandler.h"
#include "PrinterBNFactory.h"
#include "PrinterBN.h"

static PrinterBNFactory bn_factory;

PrinterBNFactory::PrinterBNFactory()
{
  PrinterHandler::reg("BN", this);
}

PrinterBNFactory::~PrinterBNFactory()
{
  ;
}

PrinterHandler* PrinterBNFactory::createObject() 
{
  PrinterHandler* printerBN = new PrinterBN();
  return printerBN;
}
