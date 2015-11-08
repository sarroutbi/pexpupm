#ifndef OPTION_EXIT_TEXT_H
#define OPTION_EXIT_TEXT_H

#include <string>
#include "OptionExit.h"
#include "OptionText.h"
#include "OptionSecureText.h"

class OptionExitText : public OptionExit, OptionText, OptionSecureText
{
public:
  OptionExitText(const std::string& text,
                 const uint8_t& pos);
  ~OptionExitText();
  virtual void Display();
  virtual bool IsUserSecure() const { return OptionSecureText::IsUserSecure(); };
  virtual GameAction* GetGameAction();
};

#endif // OPTION_EXIT_TEXT_H
