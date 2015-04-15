#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <string>
#include <vector>
#include "Pile.h"



/**
  * class Movement
  * 
  */

class Movement
{
public:

  /**
   * Empty Constructor
   */
  Movement ();

  /**
   * Empty Destructor
   */
  virtual ~Movement ();


private:
  Pile destination;
  Pile source;
public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  


  /**
   * Set the value of destination
   * @param new_var the new value of destination
   */
  void setDestination (Pile new_var)   {
      destination = new_var;
  }

  /**
   * Get the value of destination
   * @return the value of destination
   */
  Pile getDestination () {
    return destination;
  }

  /**
   * Set the value of source
   * @param new_var the new value of source
   */
  void setSource (Pile new_var) {
      source = new_var;
  }

  /**
   * Get the value of source
   * @return the value of source
   */
  Pile getSource () {
    return source;
  }
private:
  void initAttributes () ;

};

#endif // MOVEMENT_H
