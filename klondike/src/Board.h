#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "Movement.h"
#include "BoardLayout.h"


/**
  * class Board
  * 
  */

class Board
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  Board ();

  /**
   * Empty Destructor
   */
  virtual ~Board ();


  /**
   * @return bool
   * @param  movement
   */
  bool Move (Movement movement);

  /**
   * @return BoardLayout
   */
  BoardLayout GetLayout ();
};

#endif // BOARD_H
