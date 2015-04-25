#include <assert.h>
#include "Ticket.h"
#include "PrintVisitor.h"

Ticket::Ticket() : m_header("HEADER"), m_footer("FOOTER")
{
  ;
}

Ticket::~Ticket()
{
  ;
}

void Ticket::addLine(TicketLine* line)
{
  assert(line);
  m_lines.push_back(line);
}

std::string Ticket::getPrintout()
{
  std::string ticket;
  ticket += "\n";
  ticket += m_header;
  ticket += "\n\n";
  std::vector<TicketLine*>::iterator it;
  PrintVisitor visitor;
  for (it = m_lines.begin(); it != m_lines.end(); it++) {
    (*it)->accept(visitor);
  }
  ticket += visitor.getLinePrintout();
  ticket += '\n';
  ticket += m_footer;
  ticket += "\n\n";

  return ticket;
}

