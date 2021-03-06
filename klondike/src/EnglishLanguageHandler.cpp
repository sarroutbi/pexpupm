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
  m_dict[AVAILABLE] = "Available";
  m_dict[OPTIONS] = "Options";
  m_dict[MOVEMENT] = "Movement";
  m_dict[MOVEMENTS] = "Movements";
  m_dict[AVAILABLE_MOVEMENTS] = "Available Movements";
  m_dict[DESTINATION_TABLEAU] = "Destination Tableau";
  m_dict[ORIGIN_TABLEAU] = "Origin Tableau";
  m_dict[DESTINATION_FOUNDATION] = "Destination Foundation";
  m_dict[ORIGIN_FOUNDATION] = "Origin Foundation";
  m_dict[CARD_AMOUNT] = "Card Amount";
  m_dict[YES_CHARS] = "Yy";
}
