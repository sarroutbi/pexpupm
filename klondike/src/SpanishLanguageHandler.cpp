#include "SpanishLanguageHandler.h"

SpanishLanguageHandler::SpanishLanguageHandler()
{
  initDict();
}

SpanishLanguageHandler::~SpanishLanguageHandler()
{
  ;
}

void SpanishLanguageHandler::initDict() 
{
  m_dict[MOVE]  = "Mover";
  m_dict[RESET] = "Empezar";
  m_dict[EXIT]  = "Salir";
  m_dict[CARD]  = "Carta";
  m_dict[BOARD] = "Tablero";
  m_dict[PILE]  = "Pila";
}
