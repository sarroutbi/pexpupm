#include <iostream>
#include "OptionResetGameText.h"
#include "LanguageMap.h"
#include "LanguageHandler.h"

OptionResetGameText::OptionResetGameText()
{
  ;
}

OptionResetGameText::~OptionResetGameText()
{
  ;
}

void OptionResetGameText::display()
{
  ;
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

