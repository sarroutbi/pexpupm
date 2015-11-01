#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include <stdint.h>
#include "Suit.h"

class Card
{
public:
  Card (Suit* suit, const uint8_t number);
  ~Card ();
  Suit* GetSuit() const;
  uint8_t GetNumber() const;
  const std::string ToString() const;
  const std::string ToShortString() const;
  void TurnDown() { m_turnedDown = true; }
  void TurnUp() { m_turnedDown = false; }
  bool isTurnedDown() const { return m_turnedDown; }

protected:
  uint8_t m_number;
  Suit* m_suit;
  bool m_turnedDown;
};

#endif // CARD_H
