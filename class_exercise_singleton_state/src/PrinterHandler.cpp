#include "PrinterHandler.h"
#include "PrinterFactory.h"

static std::map<std::string, PrinterFactory*>* m_facMap = NULL;

PrinterHandler::PrinterHandler()
{
  ;
}

PrinterHandler::~PrinterHandler()
{
  delete m_facMap;
}

void PrinterHandler::reg(const std::string& name, PrinterFactory* factory)
{
  if(m_facMap == NULL) {
    m_facMap = new std::map<std::string, PrinterFactory*>;
  }
  (*m_facMap)[name] = factory;
}

PrinterHandler* PrinterHandler::getInstance(const std::string& name)
{
  PrinterHandler* printer = NULL;
  if((*m_facMap)[name]) {
    printer = (*m_facMap)[name]->createObject();
  }
  return printer;
}
