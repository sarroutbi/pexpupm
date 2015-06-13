#ifndef OPTION_MOVE_TEXT_H
#define OPTION_MOVE_TEXT_H

#include <string>
#include "OptionMove.h"

class OptionMoveText : public OptionMove
{
public:
  OptionMoveText();
  ~OptionMoveText();
  virtual void display();
  virtual GameAction* getGameAction();
protected:
private:
};

#endif // OPTION_MOVE_H
