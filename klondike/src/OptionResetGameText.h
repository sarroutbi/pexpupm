#ifndef OPTION_RESET_GAME_TEXT_H
#define OPTION_RESET_GAME_TEXT_H

#include <string>
#include "OptionResetGame.h"
#include "OptionText.h"

class OptionResetGameText : public OptionResetGame, OptionText
{
public:
  OptionResetGameText(const std::string& text,
                      const uint8_t& pos);
  ~OptionResetGameText();
  virtual void display();
  virtual GameAction* getGameAction();
protected:
};

#endif // OPTION_RESET_GAME_H
