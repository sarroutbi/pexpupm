#ifndef GAME_ACTION_H
#define GAME_ACTION_H

#include "BoardLayout.h"

class GameAction
{
public:
  GameAction ();
  ~GameAction ();
  virtual void PerformAction(BoardLayout& layout) const = 0;
};

#endif // GAME_ACTION_H
