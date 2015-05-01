#ifndef GAME_ACTION_H
#define GAME_ACTION_H

#include "BoardLayout.h"

/**
  * class GameAction
  * 
  */
class GameAction
{
public:

  /**
   * Empty Constructor
   */
  GameAction ();

  /**
   * Empty Destructor
   */
  ~GameAction ();

  /**
   * Action performer
   */
  virtual void PerformAction(BoardLayout& layout) const = 0;
};

#endif // GAME_ACTION_H
