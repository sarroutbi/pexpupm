#ifndef OPTION_RESET_GAME_TEXT_H
#define OPTION_RESET_GAME_TEXT_H

#include <string>
#include "OptionResetGame.h"
#include "OptionText.h"
#include "OptionSecureText.h"

class OptionResetGameText : public OptionResetGame, OptionText, OptionSecureText
{
public:
  OptionResetGameText(const std::string& text,
                      const uint8_t& pos);
  ~OptionResetGameText();
  virtual void Display();
  virtual GameAction* GetGameAction();
  virtual bool IsUserSecure() const { return OptionSecureText::IsUserSecure(); };
protected:
};

#endif // OPTION_RESET_GAME_H
