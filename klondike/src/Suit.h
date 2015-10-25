#ifndef SUIT_H
#define SUIT_H

#include <string>
#include <vector>

class Suit
{
public:
 Suit(const uint8_t& suit);
  ~Suit();
 const bool operator==(const Suit& suit) { return this->m_suit == suit.m_suit;}
protected:
  uint8_t m_suit;
};

#endif // SUIT_H
