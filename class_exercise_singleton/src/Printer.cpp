#include "Printer.h"
#include "PrinterFactory.h"

static std::map<std::string, PrinterFactory*>* m_facMap = NULL;

Printer::Printer(int colors) : m_colors(colors)
{
  ;
}

Printer::~Printer()
{
  delete m_facMap;
}

void Printer::reg(const std::string& name, PrinterFactory* factory)
{
  if(m_facMap == NULL) {
    m_facMap = new std::map<std::string, PrinterFactory*>;
  }
  (*m_facMap)[name] = factory;
}

Printer* Printer::getInstance(const std::string& name)
{
  Printer* printer = NULL;
  if((*m_facMap)[name]) {
    printer = (*m_facMap)[name]->createObject();
  }
  return printer;
}
