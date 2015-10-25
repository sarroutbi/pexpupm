#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include <stdint.h>
#include "Suit.h"

class Card
{
public:
  Card (const Suit& suit, const uint8_t num);
  ~Card ();
  Suit getSuit();
  uint8_t getNumber();
protected:
  uint8_t m_number;
  Suit m_suit;
private:
  bool m_turned;
};

#endif // CARD_H
