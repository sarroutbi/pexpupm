#include <assert.h>
#include <stdint.h>
#include <iostream>
#include "Deck.h"

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

bool Deck::Push (Card* card)
{
  assert(card);
  card->TurnDown();
  m_card_pile.push_back(card);
}

Card* Deck::Pop ()
{
  if(m_card_pile.size() == 0) {
    return NULL;
  }
  Card* ret = m_card_pile.front();
  m_card_pile.pop_back();
  return ret;
}

void Deck::Reset ()
{
  assert(m_deck_builder);
  m_deck_builder->CreateInitialDeck(this);
  m_initial_size = m_card_pile.size();
}

bool Deck::Full () const
{
  return (m_initial_size && 
  (m_card_pile.size() == m_initial_size));
}

uint8_t Deck::Size() const
{
  return m_card_pile.size();
}
