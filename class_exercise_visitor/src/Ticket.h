#ifndef __TICKET__
#define __TICKET__

#include <string>
#include <vector>

#include "TicketLine.h"

class Ticket
{
  public:
    Ticket();
    ~Ticket();
    void addLine(TicketLine* line);
    std::string getHeader() { return m_header; }
    std::string getFooter() { return m_footer; }
    std::string getPrintout();
    int getPrize();
    std::string getStock();
  private:
    std::string m_header;
    std::string m_footer;
    std::vector<TicketLine*> m_lines;
};

#endif // __TICKET__
