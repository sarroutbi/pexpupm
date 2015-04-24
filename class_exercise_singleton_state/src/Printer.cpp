#include "Printer.h"
#include "PrinterFactory.h"

static Printer* m_printer_handler = NULL;

Printer::Printer()
{
  ;
}

Printer::~Printer()
{
  ;
}

Printer* Printer::getInstance()
{
  if(!m_printer_handler) {
    m_printer_handler = new Printer();
  }
  return m_printer_handler;
}

void Printer::print(const std::string& text)
{
  m_handler->print(text);
}

void Printer::setType(const std::string& text)
{
  m_handler = PrinterHandler::getInstance(text);
}
