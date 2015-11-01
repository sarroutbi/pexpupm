#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <stdint.h>
#include <string>
#include <vector>

#include "Suit.h"
#include "Pile.h"
#include "Card.h"

const uint8_t MAX_FOUNDATION_CARDS = 13;

class Foundation : public Pile
{
public:
  Foundation (Suit* suite,
              const unsigned int max_cards = MAX_FOUNDATION_CARDS);
  ~Foundation ();
  virtual bool Push(Card* card);
  virtual Card* Pop();
  virtual bool Full () const;
  Suit* GetSuit() const { return m_suit;};
protected:
private:
  unsigned int m_max_cards;
  Suit* m_suit;
};

#endif // FOUNDATION_H
