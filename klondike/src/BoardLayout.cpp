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
  return m_pile_set.allFoundationsFull();
}


