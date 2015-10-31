#ifndef OPTION_EXIT_TEXT_H
#define OPTION_EXIT_TEXT_H

#include <string>
#include "OptionExit.h"
#include "OptionText.h"

class OptionExitText : public OptionExit, OptionText
{
public:
  OptionExitText(const std::string& text,
                 const uint8_t& pos);
  ~OptionExitText();
  virtual void display();
  virtual GameAction* getGameAction();
};

#endif // OPTION_EXIT_H
