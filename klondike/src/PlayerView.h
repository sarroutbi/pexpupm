#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <string>
#include <vector>

#include "BoardLayout.h"
#include "Movement.h"
#include "DealMode.h"
#include "GameAction.h"

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

  /**
   * @return bool
   * @param  layout
   */
  bool Draw (BoardLayout layout)
  {
    ;
  }

  /**
   * @return GameAction*
   * @param  
   */
  GameAction* GetPlayerAction() 
  {
    GameAction* action = NULL;
    return action;
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
