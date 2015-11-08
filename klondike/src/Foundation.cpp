#include <assert.h>
#include "Foundation.h"

Foundation::Foundation (const uint8_t& id, Suit* suite, 
                        const unsigned int max_cards) :
  m_id(id), m_suit(suite), m_max_cards(max_cards), Pile()
{
  ;
}

Foundation::~Foundation () 
{ 
  delete m_suit;
}

bool Foundation::Full () const
{
  return m_card_pile.size() == m_max_cards;
}

bool Foundation::Push(Card* card)
{
  bool pushed = false;
  assert(card);
  if(Size() == 0) {
    if((card->GetNumber() == 1) && (*(card->GetSuit()) == *(GetSuit()))) {
      m_card_pile.insert(m_card_pile.begin(), card);
      pushed = true;
    }
  }
  else {
    Card* last_card = m_card_pile.back();
    if((*(last_card->GetSuit()) == *(card->GetSuit()))
       && (last_card->GetNumber() == (card->GetNumber()-1))) {
      m_card_pile.insert(m_card_pile.begin(), card);
      pushed = true;
    }
  }
  return pushed;
}

Card* Foundation::Pop()
{
  Card* last_card = m_card_pile.back();
  m_card_pile.pop_back();
  return last_card;
}
