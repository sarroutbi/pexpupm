#include <assert.h>
#include "Foundation.h"

Foundation::Foundation (const Suit& suite, 
                        const unsigned int max_cards) :
m_suite(suite), m_max_cards(max_cards)
{
  ;
}

Foundation::~Foundation () 
{ 
  ;
}

bool Foundation::full () const
{
  return m_card_pile.size() == m_max_cards;
}

bool Foundation::push(Card* card)
{
  bool pushed = false;
  assert(card);
  Card* last_card = m_card_pile.back();
  if((last_card->getSuit() == card->getSuit())
     && (last_card->getNumber() == (card->getNumber()-1))) {
      m_card_pile.push_back(card);
      pushed = true;
  }
  return pushed;
}

Card* Foundation::pop()
{
  Card* last_card = m_card_pile.back();
  m_card_pile.pop_back();
  return last_card;
}
