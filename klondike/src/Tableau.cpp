#include <assert.h>
#include "Tableau.h"

Tableau::Tableau (const uint8_t& id) : m_tableau_id(id),
                                       m_in_game(false)
{
  ;
}

Tableau::~Tableau ()
{
  ;
}

bool Tableau::PushInGameCard(Card* card)
{
  bool pushed = false;
  if((Size() == 0) && card->IsHigher()) {
    m_card_pile.push_back(card);
    pushed = true;
  }
  else {
    Card* last_card = m_card_pile.back();
    assert(last_card);
    if(!last_card->GetSuit()->SameColor(*card->GetSuit()) &&
       (last_card->GetNumber() == (card->GetNumber()+1))) {
      m_card_pile.push_back(card);
      pushed = true;
    }
  }
  return pushed;
}

bool Tableau::PushOutGameCard(Card* card)
{
  Card* last_card = BottomCard();
  if(last_card) {
    last_card->TurnDown();
  }
  card->TurnUp();
  m_card_pile.push_back(card);
  return true;
}

bool Tableau::Push (Card* card)
{
  assert(card);
  bool pushed = false;
  if(m_in_game) {
    pushed = PushInGameCard(card);
  }
  else {
    pushed = PushOutGameCard(card);
  }
}

Card* Tableau::Pop ()
{
  if(m_card_pile.size() == 0) {
    return NULL;
  }
  Card* ret = m_card_pile.back();
  m_card_pile.pop_back();
  return ret;
}

bool Tableau::Full () const
{
  return (false);
}
