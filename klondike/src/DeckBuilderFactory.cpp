#include "DeckBuilderFactory.h"
#include "FrenchDeckBuilder.h"

DeckBuilderFactory::DeckBuilderFactory()
{
  ;
}

DeckBuilderFactory::~DeckBuilderFactory()
{
  ;
}

DeckBuilder* DeckBuilderFactory::CreateDeckBuilder(const e_board_type& type)
{
  if(type == BOARD_TYPE_FRENCH) {
    return new FrenchDeckBuilder;
  }
  return NULL;
}
