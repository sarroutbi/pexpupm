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

bool Foundation::Full () const
{
  return m_card_pile.size() == m_max_cards;
}

bool Foundation::Push(Card* card)
{
  bool pushed = false;
  assert(card);
  Card* last_card = m_card_pile.back();
  if((last_card->GetSuit() == card->GetSuit())
     && (last_card->GetNumber() == (card->GetNumber()-1))) {
      m_card_pile.push_back(card);
      pushed = true;
  }
  return pushed;
}

Card* Foundation::Pop()
{
  Card* last_card = m_card_pile.back();
  m_card_pile.pop_back();
  return last_card;
}
