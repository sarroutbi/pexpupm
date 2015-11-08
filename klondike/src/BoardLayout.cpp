#include "BoardLayout.h"
#include "FoundationsBuilder.h"
#include "DeckBuilderFactory.h"
#include "TableausBuilder.h"

BoardLayout::BoardLayout (const unsigned int& num_tableaus,
                          const e_board_type& type) :
  m_pile_set(NULL), m_game_finished(false)
{
  DeckBuilderFactory deck_builder_factory;
  DeckBuilder* deck_builder = deck_builder_factory.CreateDeckBuilder(type);
  TableausBuilder* tableaus_builder = new TableausBuilder(num_tableaus);
  m_pile_set = new PileSet(new FoundationsBuilder(type), deck_builder,
                           tableaus_builder);
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
  if(m_game_finished) {
    return true;
  }
  return m_pile_set->AllFoundationsFull();
}

PileSet* BoardLayout::GetPileSet() const
{ 
  return m_pile_set;
}

void BoardLayout::SetGameFinished()
{
  m_game_finished = true;
}



