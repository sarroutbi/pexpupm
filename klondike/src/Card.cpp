#include <assert.h>
#include "FrenchSuit.h"

#include "Card.h"

Card::Card (Suit* suit, const uint8_t number):
  m_suit(suit), m_number(number), m_turnedDown(true), m_higher(false)
{
  ;
}

Suit* Card::GetSuit() const
{
  return m_suit;
}

uint8_t Card::GetNumber() const
{ 
  return m_number;
}

const std::string Card::ToString() const
{
  if(!m_turnedDown) {
    return (std::to_string(GetNumber()) + " " + GetSuit()->ToString());
  }
  else {
    return "X";
  }
}

const std::string Card::ToShortString() const
{
  if(!m_turnedDown) {
    return (std::to_string(GetNumber()) + m_suit->ToChar());
  }
  else {
    return "X";
  }
}

Card::~Card ()
{ 

}
