#include <vector>
#include "PileSet.h"
#include "Foundation.h"

PileSet::PileSet()
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
