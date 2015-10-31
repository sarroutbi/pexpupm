#ifndef FRENCH_SUIT_H
#define FRENCH_SUIT_H

#include <stdint.h>
#include "Suit.h"

enum e_french_suite
{
  SUIT_HEARTS=4,
  SUIT_CLUBS=3,
  SUIT_DIAMONDS=2,
  SUIT_SPADES=1
};

class FrenchSuit : public Suit
{
public:
 FrenchSuit(const e_french_suite& suit) : Suit(suit) {};
 ~FrenchSuit() {};
 virtual const std::string ToString();
 virtual const std::string ToChar();
};

#endif // FRENCH_SUIT_H
