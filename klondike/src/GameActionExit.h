#ifndef GAME_ACTION_EXIT_H
#define GAME_ACTION_EXIT_H

#include "GameAction.h"

/**
  * class GameActionExit
  * 
  */
class GameActionExit : public GameAction
{
public:

  /**
   * Empty Constructor
   */
  GameActionExit ();

  /**
   * Empty Destructor
   */
  ~GameActionExit ();

  /**
   * Action performer
   */
  virtual void PerformAction(const BoardLayout& layout);
};

#endif // GAME_ACTION_EXIT_H
