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
  virtual bool push (Card* card) = 0;
  virtual Card* pop (Card* card) = 0;
  virtual bool full () const = 0;
  void clean ();
protected:
  std::vector<Card*> m_card_pile;
};

#endif // PILE_H
