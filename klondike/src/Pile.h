#ifndef PILE_H
#define PILE_H

#include "Card.h"
#include <string>
#include <vector>

class Pile
{
public:
  Pile ();
  virtual ~Pile ();
  virtual bool  Push (Card* card) = 0;
  virtual Card* Pop () = 0;
  virtual bool  Full () const = 0;
  Card* TopCard ();
  Card* BottomCard ();
  uint8_t Size () const { return m_card_pile.size(); };
  void Clean ();
  std::string ToShortString() const;
protected:
  std::vector<Card*> m_card_pile;
};

#endif // PILE_H
