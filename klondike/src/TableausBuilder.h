#ifndef TABLEAUS_BUILDER_H
#define TABLEAUS_BUILDER_H

#include <stdint.h>
#include "Tableau.h"
#include "Deck.h"
#include "PileSet.h"

class PileSet;

class TableausBuilder
{
public:
  TableausBuilder(const uint8_t& tableau_amount);
  ~TableausBuilder();
  void CreateInitialTableaus();
  void AssocPileSet(PileSet* pile);
  void CleanTableaus() const;
private:
  void CreateTableau(const uint8_t& tableau_number);
  uint8_t CardsInTableau(const uint8_t& tableau_number);
  uint8_t m_tableau_amount;
  std::vector<Tableau*>* m_tableau_list;
  Deck* m_deck;
};

#endif
