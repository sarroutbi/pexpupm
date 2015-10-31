#include <algorithm>
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
  m_card_pile.push_back(card);
  return true;
}

Card* Waste::Pop()
{
  Card* card = m_card_pile.back();
  return card;
}

bool Waste::Full() const
{
  return (m_full_size && (m_card_pile.size() == m_full_size));
}
