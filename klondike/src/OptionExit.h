#ifndef OPTION_EXIT_H
#define OPTION_EXIT_H

#include "Option.h"

class OptionExit : public Option
{
public:
  OptionExit()  {};
  ~OptionExit() {};
  virtual void Display() = 0;
  virtual GameAction* GetGameAction() = 0;
protected:
};

#endif // OPTION_EXIT_H
