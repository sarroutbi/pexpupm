#ifndef DECK_BUILDER_FACTORY_H
#define DECK_BUILDER_FACTORY_H

#include "BoardTypes.h"

#include <map>

class DeckBuilder;

class DeckBuilderFactory
{
public:
  DeckBuilderFactory();
  ~DeckBuilderFactory();
  DeckBuilder* CreateDeckBuilder(const e_board_type& type);
 private:
  std::map<e_board_type, DeckBuilder*> m_builder_map;
};

#endif // DECK_BUILDER_FACTORY_H

