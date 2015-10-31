#include <iostream>
#include "OptionMoveText.h"
#include "LanguageMap.h"

OptionMoveText::OptionMoveText(const std::string& text,
                               const uint8_t& pos) : OptionText(text, pos)
{
  ;
}

OptionMoveText::~OptionMoveText()
{
  ;
}

void OptionMoveText::display()
{
  std::cout << std::to_string(m_pos) << ":" << m_text << std::endl;
}

GameAction* OptionMoveText::getGameAction()
{
  char option = 0;
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();

  std::cout << lang_handler->getWord(INSERT)
            << " " << lang_handler->getWord(PILE)<< ":";
  std::cin >> option;

  // PENDING: Check Pile

  std::cout << lang_handler->getWord(INSERT)
            << " " << lang_handler->getWord(CARD)<< ":";

  // PENDING: Check Card
  
  // PENDING create ActionMove with corresponding Move and return it
  
}
