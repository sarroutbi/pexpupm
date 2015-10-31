#include "Card.h"

Card::Card (const Suit& suit, const uint8_t number):
  m_suit(suit), m_number(number)
{

}

const Suit& Card::GetSuit() const
{
  return m_suit;
}

uint8_t Card::GetNumber() const
{ 
  return m_number;
}

const std::string Card::ToString() const
{
  if(m_turned) {
    return (std::to_string(GetNumber()) + GetSuit().ToString());
  }
  else {
    return "X";
  }
}

Card::~Card ()
{ 

}
