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



  /**
   * Set the value of destination
   * @param new_var the new value of destination
   */
  void setDestination (Pile* new_var)
  {
      m_destination = new_var;
  }

  /**
   * Get the value of destination
   * @return the value of destination
   */
  Pile* getDestination ()
  {
    return m_destination;
  }

  /**
   * Set the value of source
   * @param new_var the new value of source
   */
  void setSource (Pile* new_var)
  {
      m_source = new_var;
  }

  /**
   * Get the value of source
   * @return the value of source
   */
  Pile* getSource ()
  {
    return m_source;
  }
private:
  Pile* m_source;
  Pile* m_destination;
};

#endif // MOVEMENT_H
