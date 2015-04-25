#include <sstream>
#include "TicketLine.h"

TicketLine::TicketLine(int prize,
                       const std::string& description) :
  m_prize(prize), m_description(description)
{
  ;
}

TicketLine::~TicketLine()
{
  ;
}

std::string TicketLine::getDescription()
{
  return m_description;
}

int TicketLine::getPrice()
{
  return m_prize;
}
