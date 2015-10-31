#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include <stdint.h>
#include "Suit.h"

class Card
{
public:
  Card (const Suit& suit, const uint8_t number);
  ~Card ();
  const Suit& GetSuit() const;
  uint8_t GetNumber() const;
  const std::string ToString() const;
protected:
  uint8_t m_number;
  Suit m_suit;
  bool m_turned;
};

#endif // CARD_H
