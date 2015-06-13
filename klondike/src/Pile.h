#ifndef PILE_H
#define PILE_H

#include "Card.h"
#include <string>
#include <vector>



/**
  * class Pile
  * 
  */

class Pile
{
public:
  Pile ();
  virtual ~Pile ();
  virtual bool Push (Card card) = 0;
  virtual bool Pop (Card card) = 0;
  virtual bool Full () = 0;
protected:
  std::vector<Card> m_card_pile;
};

#endif // PILE_H
