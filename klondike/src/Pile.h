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
  /**
   * Empty Constructor
   */
  Pile ();

  /**
   * Empty Destructor
   */
  virtual ~Pile ();

  /**
   * @return Card
   * @param  bool specifying if card was pushed (true) or not (false)
   */
  virtual bool Push (Card card) = 0;

  /**
   * @param  Card Card to pop
   * @return bool specifying if card was popped (true) or not (false)
   */
  virtual bool Pop (Card card) = 0;

  /**
   * @return bool specifying if pile is full or not
   */
  virtual bool Full () = 0;

protected:
  std::vector<Card> m_card_pile;
};

#endif // PILE_H
