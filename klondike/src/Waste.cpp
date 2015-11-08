#include <algorithm>
#include <assert.h>
#include "Waste.h"
#include "Card.h"

Waste::Waste ()
{
  
}

Waste::~Waste () 
{ 

}

bool Waste::Push(Card* card)
{
  assert(card);
  card->TurnUp();
  m_card_pile.insert(m_card_pile.begin(), card);
  return true;
}

Card* Waste::Pop()
{
  if(Size() == 0) {
    return NULL;
  }
  Card* card = m_card_pile.front();
  m_card_pile.erase(m_card_pile.begin());
  return card;
}

bool Waste::Full() const
{
  return (m_full_size && (m_card_pile.size() == m_full_size));
}
