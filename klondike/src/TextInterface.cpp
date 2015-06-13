#include <iostream>
#include "TextInterface.h"
#include "OptionMoveText.h"
#include "OptionExitText.h"
#include "OptionResetGameText.h"
#include "LanguageMap.h"

void TextInterface::createOptions()
{
  Option* move  = new OptionMoveText();
  Option* exit  = new OptionExitText();
  Option* reset = new OptionResetGameText();
  m_option_list[0] = move;
  m_option_list[1] = exit;
  m_option_list[2] = reset;
}

void TextInterface::displayOptions()
{
  Interface::displayOptions();
}

void TextInterface::draw(const BoardLayout& layout)
{
    
}

GameAction* TextInterface::getPlayerAction()
{
  int option = 0;

  // Prompt option
  std::cout << LanguageMap::getInstance()->getLanguageHandler()->getWord(INSERT)
  << " " << LanguageMap::getInstance()->getLanguageHandler()->getWord(OPTION)
  << ":" << std::endl;
  std::cin >> option;

  // Prompt option action
  GameAction* action = m_option_list[option]->getGameAction();
}
