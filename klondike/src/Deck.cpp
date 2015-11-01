#include <assert.h>
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include "Deck.h"

Deck::Deck () : m_initial_size(0)
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
  Card* ret = m_card_pile.back();
  m_card_pile.pop_back();
  return ret;
}

void Deck::Shuffle ()
{
  srand(unsigned(time(NULL)));
  std::random_shuffle ( m_card_pile.begin(), m_card_pile.end());
  m_initial_size = m_card_pile.size();
}

bool Deck::Full () const
{
  return (m_initial_size && 
  (m_card_pile.size() == m_initial_size));
}
