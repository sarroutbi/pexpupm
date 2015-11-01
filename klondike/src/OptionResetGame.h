#ifndef OPTION_RESET_GAME_H
#define OPTION_RESET_GAME_H

#include "Option.h"

class OptionResetGame : public Option
{
public:
  OptionResetGame()  {};
  ~OptionResetGame() {};
  virtual void Display() = 0;
  virtual GameAction* GetGameAction() = 0;
protected:
};

#endif // OPTION_RESET_GAME_H
