#ifndef ACTION_MOVE_H
#define ACTION_MOVE_H

#include "GameAction.h"

class ActionMove : public GameAction
{
public:
  ActionMove();
  explicit ActionMove(Movement* movement);
  ~ActionMove();
  virtual void PerformAction(BoardLayout* layout) const;
  void SetMovement (Movement* movement) { m_movement = movement;};
private:
  Movement* m_movement;
};

#endif //EXIT
