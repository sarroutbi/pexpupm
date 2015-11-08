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
  m_dict[OPTION] = "Opcion";
  m_dict[YES_NO] = "(S)i/(N)o";
  m_dict[AVAILABLE] = "Disponibles";
  m_dict[OPTIONS] = "Opciones";
  m_dict[MOVEMENT] = "Movimiento";
  m_dict[MOVEMENTS] = "Movimientos";
  m_dict[AVAILABLE_MOVEMENTS] = "Movimientos Disponibles";
  m_dict[DESTINATION_TABLEAU] = "Tableau de Destino";
  m_dict[ORIGIN_TABLEAU] = "Tableau de Origen";
  m_dict[DESTINATION_FOUNDATION] = "Fundacion Destino";
  m_dict[ORIGIN_FOUNDATION] = "Fundacion Origen";
  m_dict[CARD_AMOUNT] = "Numero de cartas";
  m_dict[YES_CHARS] = "Ss";
}
