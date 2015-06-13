#ifndef OPTION_MOVE_H
#define OPTION_MOVE_H

#include <string>
#include "Option.h"

class OptionMove : public Option
{
public:
  OptionMove()  {};
  ~OptionMove() {};
  virtual void display() = 0;
  virtual GameAction* getGameAction() = 0;
protected:
};

#endif // OPTION_MOVE_H
