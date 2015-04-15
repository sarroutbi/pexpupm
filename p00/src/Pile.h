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

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Pile ();

  /**
   * Empty Destructor
   */
  virtual ~Pile ();

  // Static Public attributes
  //  

  // Public attributes
  //  


  // Public attribute accessor methods
  //  


  // Public attribute accessor methods
  //  



  /**
   * @return bool
   * @param  card
   */
  virtual bool Push (Card card)
  {

  }


  /**
   * @return Card
   * @param  card
   */
  virtual Card Pop (Card card)
  {

  }

};

#endif // PILE_H
