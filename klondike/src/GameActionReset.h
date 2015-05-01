#ifndef GAME_ACTION_RESET_H
#define GAME_ACTION_RESET_H

#include "GameAction.h"

/**
  * class GameActionReset
  * 
  */
class GameActionReset : public GameAction
{
public:

  /**
   * Empty Constructor
   */
  GameActionReset ();

  /**
   * Empty Destructor
   */
  ~GameActionReset ();

  /**
   * Action performer
   */
  virtual void PerformAction(BoardLayout& layout) const;
};

#endif // GAME_ACTION_RESET_H
