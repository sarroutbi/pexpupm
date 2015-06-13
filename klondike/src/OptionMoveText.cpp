#include <iostream>
#include "OptionMoveText.h"
#include "LanguageMap.h"

OptionMoveText::OptionMoveText()
{
  ;
}

OptionMoveText::~OptionMoveText()
{
  ;
}

void OptionMoveText::display()
{
  ;
}

GameAction* OptionMoveText::getGameAction()
{
  char option = 0;
  std::cout << LanguageMap::getInstance()->getLanguageHandler()->getWord(INSERT)
            << " " << LanguageMap::getInstance()->getLanguageHandler()->getWord(PILE)<< "\n";
  std::cin >> option;
  if (option == '?') {
    // PENDING: Check Pile
  }
  std::cout << LanguageMap::getInstance()->getLanguageHandler()->getWord(INSERT)
            << " " << LanguageMap::getInstance()->getLanguageHandler()->getWord(CARD)<< "\n";
  if (option == 'Y') {
    // PENDING return Reset Action and check card
    return NULL;
  }
}
