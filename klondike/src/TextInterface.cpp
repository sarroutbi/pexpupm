#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include "TextInterface.h"
#include "OptionMoveText.h"
#include "OptionExitText.h"
#include "OptionResetGameText.h"
#include "LanguageMap.h"

TextInterface::TextInterface()
{
  CreateOptions();
}

TextInterface::~TextInterface()
{
  DeleteOptions();
}

void TextInterface::CreateOptions()
{
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();
  Option* move  = new OptionMoveText(lang_handler->getWord(MOVE), 0);
  Option* exit  = new OptionExitText(lang_handler->getWord(EXIT), 1);
  Option* reset = new OptionResetGameText(lang_handler->getWord(RESET), 2);
  m_option_list[0] = move;
  m_option_list[1] = exit;
  m_option_list[2] = reset;
}

void TextInterface::DeleteOptions() const
{
  std::map<uint8_t, Option*>::const_iterator opit = m_option_list.begin();
  for (; opit != m_option_list.end(); opit++) {
    delete opit->second;
  }
}

void TextInterface::DisplayOptions()
{
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();
  std::cout << lang_handler->getWord(AVAILABLE)
  << " " << lang_handler->getWord(OPTIONS)
  << ":" << std::endl;
  Interface::DisplayOptions();
}

void TextInterface::Draw(const BoardLayout& layout)
{
  PileSet* pile_set = layout.GetPileSet();
  assert(pile_set);
  system("clear");
  Draw(pile_set->GetDeck());
  std::cout << " ";
  Draw(pile_set->GetWaste());
  std::cout << std::endl;
}

int TextInterface::PromptOption() const
{
  int option = -1;
  // Prompt option
  LanguageHandler* lang_handler =
    LanguageMap::getInstance()->getLanguageHandler();
  while(option < 0 && (m_option_list.find(option) == m_option_list.end())) {
    std::cout << lang_handler->getWord(INSERT) <<
    " " << lang_handler->getWord(OPTION) << ":" ;
    std::cin >> option;
  }
  return option;
}

GameAction* TextInterface::GetPlayerAction()
{
  int option = 0;
  DisplayOptions();
  option = PromptOption();
  GameAction* action = m_option_list[option]->getGameAction();
}

void TextInterface::Draw(Deck* deck) const
{
  assert(deck);
  if(deck->Size() == 0) {
    std::cout << "[ ]";
  }
  else {
    std::cout << "[X]";
  }
}

void TextInterface::Draw(Waste* waste) const
{
  assert(waste);
  if(waste->Size() > 0) {
    std::cout << "[" << waste->TopCard()->ToShortString() << "]";
  }
  else {
    std::cout << "[ ]";
  }
}
