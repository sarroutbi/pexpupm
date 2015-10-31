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
  virtual bool  Push (Card* card) = 0;
  virtual Card* Pop () = 0;
  virtual bool  Full () const = 0;
  Card* TopCard () {
    if(Size() == 0) { 
      return NULL; 
    }
    return m_card_pile.at(0);
  };
  virtual uint8_t Size () const { return m_card_pile.size(); };
  void Clean ();
protected:
  std::vector<Card*> m_card_pile;
};

#endif // PILE_H
