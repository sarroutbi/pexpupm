#include <vector>
#include "PileSet.h"
#include "Foundation.h"

PileSet::PileSet() : m_foundations(), m_tableaus(),
  m_deck(NULL), m_waste(NULL)
{
  ;
}
PileSet::~PileSet()
{
  ;
}

bool PileSet::AllFoundationsFull()
{
  std::vector<Pile*>::const_iterator it;
  for (it = m_foundations.begin(); it != m_foundations.end(); it++) {
    if(!((*it)->Full())) {
      return false;
    }
  }
  return true;
}
