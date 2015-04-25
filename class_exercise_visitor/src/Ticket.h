#ifndef __TICKET__
#define __TICKET__

class Ticket
{
  public:
    Ticket();
    ~Ticket();
  private:
    Header m_header;
    Footer m_footer;
    std::list<Lines> m_lines;
}
#endif // __TICKET__
