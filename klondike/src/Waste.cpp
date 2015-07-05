#include <algorithm>
#include "Waste.h"
#include "Card.h"

Waste::Waste ()
{
  
}

Waste::~Waste () 
{ 

}

bool Waste::push(Card* card)
{
  m_card_pile.push_back(card);
  return true;
}

Card* Waste::pop(Card* card)
{
  Card* ret = NULL;
  std::vector<Card*>::iterator it = 
    find(m_card_pile.begin(), m_card_pile.end(),
         card);

  if (it != m_card_pile.end()) {
    return *it;
  }
  return NULL;
}

bool Waste::full() const
{
  return (m_full_size && (m_card_pile.size() == m_full_size));
}


