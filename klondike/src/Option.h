#ifndef OPTION_H
#define OPTION_H

#include <string>
#include "GameAction.h"

class Option
{
public:
  Option() {};
  virtual void display() = 0;
  virtual GameAction* getGameAction() = 0;
};

#endif // OPTION_H
