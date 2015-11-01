#include "Pile.h"

Card* Pile::TopCard ()
{
  if(Size() == 0) {
    return NULL;
  }
  return m_card_pile.at(0);
}

Card* Pile::BottomCard ()
{
  if(Size() == 0) {
    return NULL;
  }
  return m_card_pile.at(Size()-1);
}

Pile::Pile () : m_card_pile()
{
  ;
}

Pile::~Pile ()
{ 
  ;
}

void Pile::Clean ()
{
  m_card_pile.clear();
}

std::string Pile::ToShortString() const
{
  std::string cards;
  if(Size() > 0) {
    for (auto card_it : m_card_pile) {
      cards += ",";
      cards += card_it->ToShortString();
    }
    cards.erase(0, 1);
  }
  return cards;
}
