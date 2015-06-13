#include "EnglishLanguageHandler.h"

EnglishLanguageHandler::EnglishLanguageHandler()
{
  initDict();
}

EnglishLanguageHandler::~EnglishLanguageHandler()
{
  ;
}

void EnglishLanguageHandler::initDict() 
{
  m_dict[MOVE]  = "Move";
  m_dict[RESET] = "Reset";
  m_dict[EXIT]  = "Exit";
  m_dict[CARD]  = "Card";
  m_dict[BOARD] = "Board";
  m_dict[PILE]  = "Pile";
}
