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

const bool FrenchSuit::SameColor(const Suit& suit) const
{
  bool same_color = false;
  if(GetSuit() == suit.GetSuit()) {
    same_color = true;
  }
  else if(GetSuit() == SUIT_HEARTS && suit.GetSuit() == SUIT_DIAMONDS) {
    same_color = true;
  }
  else if(GetSuit() == SUIT_DIAMONDS && suit.GetSuit() == SUIT_HEARTS) {
    same_color = true;
  }
  else if(GetSuit() == SUIT_CLUBS && suit.GetSuit() == SUIT_SPADES) {
    same_color = true;
  }
  else if(GetSuit() == SUIT_SPADES && suit.GetSuit() == SUIT_CLUBS) {
    same_color = true;
  }
  return same_color;
}
