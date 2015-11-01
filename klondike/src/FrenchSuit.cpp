#include "FrenchSuit.h"

const std::string FrenchSuit::ToString() const
{
  switch(GetSuit()) {
  case SUIT_HEARTS:
    return "HEARTS";
  case SUIT_CLUBS:
    return "CLUBS";
  case SUIT_DIAMONDS:
    return "DIAMONDS";
  case SUIT_SPADES:
    return "SPADES";
  default:
    return "UNDEFINED";
  }
}

const std::string FrenchSuit::ToChar() const
{
  switch(GetSuit()) {
  case SUIT_HEARTS:
    return "H";
  case SUIT_CLUBS:
    return "C";
  case SUIT_DIAMONDS:
    return "D";
  case SUIT_SPADES:
    return "S";
  default:
    return "-";
  }
}
