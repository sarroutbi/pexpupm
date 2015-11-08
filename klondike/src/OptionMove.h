#ifndef OPTION_MOVE_H
#define OPTION_MOVE_H

#include <string>
#include "Option.h"

class OptionMove : public Option
{
public:
  OptionMove()  {};
  virtual ~OptionMove() {};
  virtual void Display() = 0;
  virtual GameAction* GetGameAction() = 0;
protected:
};

#endif // OPTION_MOVE_H
