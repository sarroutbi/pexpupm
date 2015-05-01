#include "BoardLayout.h"

BoardLayout::BoardLayout (const unsigned int num_tableaus) 
{
  ;
}

BoardLayout::~BoardLayout ()
{ 
  ;
}

void BoardLayout::ResetPiles ()
{
  ;
}

bool BoardLayout::GameFinished ()
{
  std::vector<Foundation>::const_iterator it;

  for (it = m_foundations.begin(); it != m_foundations.end(); it++) {
    if(!((*it).Completed())) {
      return false;
    }
  }
  
  return true;
}


