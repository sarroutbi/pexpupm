#ifndef SUIT_H
#define SUIT_H

#include <string>
#include <vector>

class Suit
{
public:
 explicit Suit(const uint8_t& suit);
 virtual ~Suit();
 const uint8_t GetSuit() const { return m_suit; };
 const bool operator==(const Suit& suit) const { return m_suit == suit.m_suit;}
 virtual const bool SameColor(const Suit& suit) const = 0;
 virtual const std::string ToString() const = 0;
 virtual const std::string ToChar() const = 0;
protected:
  uint8_t m_suit;
};

#endif // SUIT_H
