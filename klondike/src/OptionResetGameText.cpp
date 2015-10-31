#include <iostream>
#include "OptionResetGameText.h"
#include "LanguageMap.h"
#include "LanguageHandler.h"

OptionResetGameText::OptionResetGameText(const std::string& text,
                                         const uint8_t& pos) : OptionText(text, pos)
{
  ;
}

OptionResetGameText::~OptionResetGameText()
{
  ;
}

void OptionResetGameText::display()
{
  std::cout << std::to_string(m_pos) << ":" << m_text << std::endl;
}

GameAction* OptionResetGameText::getGameAction()
{
  char option = 0;
  std::cout << LanguageMap::getInstance()->getLanguageHandler()->getWord(SURE)
            << "?" << LanguageMap::getInstance()->getLanguageHandler()->getWord(YES_NO)<< "\n";
  std::cin >> option;
  if (option == 'Y' || option == 'y') {
    // Pending return Reset Action
    return NULL;
  }
}

