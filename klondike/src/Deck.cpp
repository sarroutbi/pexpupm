#include <assert.h>
#include <stdint.h>
#include "Deck.h"

// Constructors/Destructors
//  

Deck::Deck () :
  m_initial_size(0),
  m_deck_builder(NULL)
{
  ;
}

Deck::~Deck ()
{ 
  ;
}

bool Deck::push (Card* card)
{
  return false;
}

Card* Deck::pop ()
{
  Card* ret = *(m_card_pile.begin());
  m_card_pile.erase(m_card_pile.begin());
  return ret;
}

void Deck::reset ()
{
  assert(m_deck_builder);
  m_deck_builder->createInitialDeck(this);
  m_initial_size = m_card_pile.size();
}

bool Deck::full () const
{
  return (m_initial_size && 
  (m_card_pile.size() == m_initial_size));
}
