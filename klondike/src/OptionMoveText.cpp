#include <iostream>
#include <assert.h>
#include "OptionMoveText.h"
#include "LanguageMap.h"
#include "ActionMove.h"

OptionMoveText::OptionMoveText(const std::string& text,
                               const uint8_t& pos) : m_movement_builder(),
                                                     OptionText(text, pos)
{
  ;
}

OptionMoveText::~OptionMoveText()
{
  ;
}

void OptionMoveText::Display()
{
  std::cout << std::to_string(m_pos) << ":" << m_text << std::endl;
}

void OptionMoveText::ShowMovements()
{
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();

  std::cout << lang_handler->getWord(AVAILABLE_MOVEMENTS)<< ":";
  std::cout << std::endl;

  std::vector<Movement*>* movement_list = m_movement_builder.GetMovementList();
  assert(movement_list);
  for (auto move_it : *movement_list) {
    std::cout << std::to_string(move_it->GetId()) << " - " << move_it->ToString();
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

char OptionMoveText::PromptMovementOption()
{
  char option;
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();
  std::cout << lang_handler->getWord(INSERT)
            << " " << lang_handler->getWord(MOVEMENT)<< ":";
  std::cin >> option;
  // Set char number ('1') to integer 1
  option = option - '0';
  return option;
}

GameAction* OptionMoveText::PromptMovement()
{
  Movement* movement = NULL;
  char option = 0;

  do {
    ShowMovements();
    option = PromptMovementOption();
  } while (!(movement = m_movement_builder.GetMovementWithId(option)));

  GameAction* action = new ActionMove(movement);
  return action;
}

GameAction* OptionMoveText::GetGameAction()
{
  GameAction* action = PromptMovement();
  return action;
}
