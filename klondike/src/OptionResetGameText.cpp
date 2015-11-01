#include <iostream>
#include "OptionResetGameText.h"
#include "LanguageMap.h"
#include "LanguageHandler.h"
#include "ActionReset.h"

OptionResetGameText::OptionResetGameText(const std::string& text,
                                         const uint8_t& pos) : OptionText(text, pos)
{
  ;
}

OptionResetGameText::~OptionResetGameText()
{
  ;
}

void OptionResetGameText::Display()
{
  std::cout << std::to_string(m_pos) << ":" << m_text << std::endl;
}

GameAction* OptionResetGameText::GetGameAction()
{
  char option = 0;
  return new ActionReset;
}

