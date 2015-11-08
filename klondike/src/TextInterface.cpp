#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include "TextInterface.h"
#include "OptionMoveText.h"
#include "OptionExitText.h"
#include "OptionResetGameText.h"
#include "LanguageMap.h"

TextInterface::TextInterface() : m_pile_set(nullptr)
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
  std::cout << std::endl;
  std::cout << lang_handler->getWord(AVAILABLE)
  << " " << lang_handler->getWord(OPTIONS)
  << ":" << std::endl;
  Interface::DisplayOptions();
}

void TextInterface::accept(const TextInterfaceDrawVisitor& draw_visitor)
{
  draw_visitor.visitTextInterface(this);
}

void TextInterface::Draw(const BoardLayout& layout)
{
  PileSet* pile_set = layout.GetPileSet();
  assert(pile_set);
  m_pile_set = pile_set;
  system("clear");
  TextInterfaceDrawVisitor draw_visitor;
  accept(draw_visitor);
}

int TextInterface::PromptOption() const
{
  int option = -1;
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
  GameAction* action = m_option_list[option]->GetGameAction();
  return action;
}
