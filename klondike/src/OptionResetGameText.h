#ifndef OPTION_RESET_GAME_TEXT_H
#define OPTION_RESET_GAME_TEXT_H

#include <string>
#include "OptionResetGame.h"

class OptionResetGameText : public OptionResetGame
{
public:
  OptionResetGameText();
  ~OptionResetGameText();
  virtual void display();
  virtual GameAction* getGameAction();
protected:
};

#endif // OPTION_RESET_GAME_H
