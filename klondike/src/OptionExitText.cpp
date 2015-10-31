#include <iostream>
#include "OptionExitText.h"
#include "ActionExit.h"

OptionExitText::OptionExitText(const std::string& text,
                               const uint8_t& pos) : OptionText(text, pos)
{
  ;
}

OptionExitText::~OptionExitText()
{
  ;
}

void OptionExitText::display()
{
  std::cout << std::to_string(m_pos) << ":" << m_text << std::endl;
}

GameAction* OptionExitText::getGameAction()
{
  return new ActionExit;
}

