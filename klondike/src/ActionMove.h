#ifndef ACTION_MOVE_H
#define ACTION_MOVE_H

#include "GameAction.h"

class ActionMove : public GameAction
{
public:
  ActionMove()  {};
  ~ActionMove() {};
  virtual void PerformAction(BoardLayout& layout) const;
private:
};

#endif //EXIT
