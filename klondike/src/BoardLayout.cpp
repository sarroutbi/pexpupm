#include "BoardLayout.h"
#include "FoundationsBuilder.h"

BoardLayout::BoardLayout (const unsigned int& num_tableaus,
                          const e_board_type& type) :
  m_pile_set(NULL)
{
  m_pile_set = new PileSet(new FoundationsBuilder(type));
}

BoardLayout::~BoardLayout ()
{ 
  delete m_pile_set;
}

void BoardLayout::ResetPiles ()
{
  ;
}

bool BoardLayout::GameFinished ()
{
  return m_pile_set->allFoundationsFull();
}


