#ifndef OPTION_EXIT_TEXT_H
#define OPTION_EXIT_TEXT_H

#include <string>
#include "OptionExit.h"

class OptionExitText : public OptionExit
{
public:
  OptionExitText();
  ~OptionExitText();
  virtual void display();
  virtual GameAction* getGameAction();
protected:
};

#endif // OPTION_EXIT_H
