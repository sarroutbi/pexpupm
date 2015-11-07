#ifndef TABLEAU_BUILDER_H
#define TABLEAU_BUILDER_H

#include <stdint.h>
#include "Tableau.h"
#include "Deck.h"
#include "PileSet.h"

class Tableau;

class TableauBuilder
{
public:
  TableauBuilder(const uint8_t& tableau_amount);
  ~TableauBuilder();
  void CreateTableausFromDeck();
  void AssocPile(PileSet* pile);
private:
  void CreateTableau(const uint8_t& tableau_number);
  uint8_t CardsInTableau(const uint8_t& tableau_number);
  uint8_t m_tableau_amount;
  std::vector<Tableau*>* m_tableau_list;
  Deck* m_deck;
};

#endif
