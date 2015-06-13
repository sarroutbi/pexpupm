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
  m_dict[SURE]  = "Sure";
  m_dict[INTRODUCE] = "Introduce";
  m_dict[INSERT] = "Insert";
  m_dict[OPTION] = "Option";
  m_dict[YES_NO] = "(Y)es/(N)o";
}
