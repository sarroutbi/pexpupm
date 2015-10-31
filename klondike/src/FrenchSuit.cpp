#include "FrenchSuit.h"

const std::string FrenchSuit::ToString()
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

const std::string FrenchSuit::ToChar()
{
  switch(GetSuit()) {
  case SUIT_HEARTS:
    return "♥";
  case SUIT_CLUBS:
    return "♣";
  case SUIT_DIAMONDS:
    return "♦";
  case SUIT_SPADES:
    return "♠";
  default:
    return "-";
  }
}
