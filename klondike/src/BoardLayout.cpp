#include "BoardLayout.h"
#include "FoundationsBuilder.h"
#include "DeckBuilderFactory.h"

BoardLayout::BoardLayout (const unsigned int& num_tableaus,
                          const e_board_type& type) :
  m_pile_set(NULL)
{
  DeckBuilderFactory deck_builder_factory;
  DeckBuilder* deck_builder = deck_builder_factory.CreateDeckBuilder(type);
  m_pile_set = new PileSet(new FoundationsBuilder(type), deck_builder);
}

BoardLayout::~BoardLayout ()
{ 
  delete m_pile_set;
}

void BoardLayout::ResetPiles ()
{
  m_pile_set->ResetPiles();
}

bool BoardLayout::GameFinished () const
{
  return m_pile_set->AllFoundationsFull();
}

