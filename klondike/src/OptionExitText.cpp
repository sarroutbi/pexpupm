#include <iostream>
#include "OptionExitText.h"
#include "ActionExit.h"
#include "LanguageMap.h"

OptionExitText::OptionExitText(const std::string& text,
                               const uint8_t& pos) : OptionText(text, pos)
{
  ;
}

OptionExitText::~OptionExitText()
{
  ;
}

void OptionExitText::Display()
{
  std::cout << std::to_string(m_pos) << ":" << m_text << std::endl;
}

GameAction* OptionExitText::GetGameAction()
{
  if(IsUserSecure()) {
    return new ActionExit;
  }
  return NULL;
}

