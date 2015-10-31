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
  m_dict[MOVE]   = "Mover";
  m_dict[RESET]  = "Empezar";
  m_dict[EXIT]   = "Salir";
  m_dict[CARD]   = "Carta";
  m_dict[BOARD]  = "Tablero";
  m_dict[PILE]   = "Pila";
  m_dict[SURE]   = "Seguro";
  m_dict[INTRODUCE] = "Introduzca";
  m_dict[INSERT] = "Inserte";
  m_dict[OPTION] = "Opción";
  m_dict[YES_NO] = "(S)í/(N)o";
  m_dict[AVAILABLE] = "Disponibles";
  m_dict[OPTIONS] = "Opciones";
}
