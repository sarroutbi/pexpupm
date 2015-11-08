#ifndef OPTION_H
#define OPTION_H

#include <string>
#include "GameAction.h"

class Option
{
public:
  Option() {};
  virtual ~Option() {};
  virtual void Display() = 0;
  virtual GameAction* GetGameAction() = 0;
};

#endif // OPTION_H
