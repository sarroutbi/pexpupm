#include <assert.h>
#include "TableausBuilder.h"

TableausBuilder::TableausBuilder(const uint8_t& tableau_amount) : 
  m_tableau_amount(tableau_amount), m_tableau_list(NULL), m_deck(NULL)
{
  ;
}

TableausBuilder::~TableausBuilder()
{
  ;
}

void TableausBuilder::AssocPileSet(PileSet* pile)
{
  assert(pile);
  m_tableau_list = pile->GetTableaus();
  m_deck = pile->GetDeck();
  assert(m_tableau_list);
  assert(m_deck);
}

uint8_t TableausBuilder::CardsInTableau(const uint8_t& tableau_number)
{
  return tableau_number + 1;
}

void TableausBuilder::CreateTableau(const uint8_t& tableau_number)
{
  assert(m_deck);
  assert(m_tableau_list);
  Tableau* tableau = new Tableau(tableau_number);
  uint8_t cards_to_put = CardsInTableau(tableau_number);
  while(cards_to_put != 0) {
    Card* card = m_deck->Pop();
    tableau->Push(card);
    cards_to_put--;
  }
  tableau->SetInGame();
  m_tableau_list->push_back(tableau);
}

void TableausBuilder::CreateInitialTableaus()
{
  uint8_t tableau_counter;
  m_tableau_list->clear();
  for(tableau_counter=0; tableau_counter < m_tableau_amount; tableau_counter++) {
    CreateTableau(tableau_counter);
  }
}
