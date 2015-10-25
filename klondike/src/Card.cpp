#include "Card.h"

Card::Card (const Suit& suit, const uint8_t number):
  m_suit(suit), m_number(number)
{

}

Suit Card::getSuit()
{
  return m_suit;
}

uint8_t Card::getNumber()
{ 
  return m_number;
}

Card::~Card ()
{ 

}
