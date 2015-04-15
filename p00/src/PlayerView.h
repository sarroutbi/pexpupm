#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <string>
#include <vector>

#include "BoardLayout.h"
#include "Movement.h"
#include "DealMode.h"

/**
  * class PlayerView
  * 
  */
class PlayerView
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  PlayerView ();

  /**
   * Empty Destructor
   */
  virtual ~PlayerView ();

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
   */
  bool NewGame ()
  {
  }


  /**
   * @return Movement
   * @param  layout
   */
  Movement GetMovement (BoardLayout layout)
  {
  }


  /**
   * @return DealMode
   */
  DealMode GetDealMode ()
  {
  }


  /**
   * @return bool
   * @param  layout
   */
  bool Draw (BoardLayout layout)
  {
  }

protected:

  // Static Protected attributes
  //  

  // Protected attributes
  //  

public:


  // Protected attribute accessor methods
  //  

protected:

public:


  // Protected attribute accessor methods
  //  

protected:


private:

  // Static Private attributes
  //  

  // Private attributes
  //  

public:


  // Private attribute accessor methods
  //  

private:

public:


  // Private attribute accessor methods
  //  

private:



};

#endif // PLAYERVIEW_H
