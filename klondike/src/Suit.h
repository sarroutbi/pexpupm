#ifndef SUIT_H
#define SUIT_H

#include <string>
#include <vector>

class Suit
{
public:
 explicit Suit(const uint8_t& suit);
  ~Suit();
 const uint8_t getSuit() const { return m_suit; };
 const bool operator==(const Suit& suit) const { return m_suit == suit.m_suit;}
 virtual const std::string ToString() const { return "UNDEFINED"; };
 virtual const std::string ToChar() const { return "X"; };
protected:
  uint8_t m_suit;
};

#endif // SUIT_H
