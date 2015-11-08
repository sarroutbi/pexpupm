#include <assert.h>
#include <vector>

#include "PileSet.h"
#include "Foundation.h"
#include "Deck.h"
#include "Waste.h"

PileSet::PileSet(FoundationsBuilder* foundations_builder,
                 DeckBuilder* deck_builder,
                 TableausBuilder* tableaus_builder) :
  m_foundations(), m_tableaus(), m_deck(NULL), m_waste(NULL),
  m_foundations_builder(foundations_builder),
  m_deck_builder(deck_builder),
  m_tableaus_builder(tableaus_builder)
{
  assert(m_foundations_builder);
  assert(m_deck_builder);
  assert(m_tableaus_builder);
  m_deck = new Deck();
  m_waste = new Waste();
  m_foundations_builder->SetFoundations(m_foundations);
  m_deck_builder->CreateInitialDeck(m_deck);
  m_tableaus_builder->AssocPileSet(this);
  ResetPiles();
}

PileSet::~PileSet()
{
  delete m_deck;
  delete m_waste;
  delete m_deck_builder;
  delete m_foundations_builder;
  delete m_tableaus_builder;
  CleanTableaus();
  CleanFoundations();
}

void PileSet::CleanTableaus()
{
  for (auto tableau_it : m_tableaus) {
    delete tableau_it;
  }
}

void PileSet::CleanFoundations()
{
  for (auto foundation_it : m_foundations) {
    delete foundation_it;
  }
}

bool PileSet::AllFoundationsFull() const
{
  assert(m_foundations.size() != 0);
  std::vector<Foundation*>::const_iterator it;
  for (it = m_foundations.begin(); it != m_foundations.end(); it++) {
    if(!((*it)->Full())) {
      return false;
    }
  }
  return true;
}

bool PileSet::ResetPiles()
{
  ResetFoundations();
  ResetTableaus();
  m_deck->Clean();
  m_deck_builder->CreateInitialDeck(m_deck);
  m_deck->Shuffle();
  m_waste->Clean();
  m_tableaus_builder->CreateInitialTableaus();
}

bool PileSet::ResetFoundations()
{
  std::vector<Foundation*>::iterator it = m_foundations.begin();
  for (; it != m_foundations.end(); it++) {
    (*it)->Clean();
  }
}

bool PileSet::ResetTableaus()
{
  std::vector<Tableau*>::iterator it = m_tableaus.begin();
  for (; it != m_tableaus.end(); it++) {
    (*it)->Clean();
  }
}

Foundation* PileSet::GetFoundation(const uint8_t& id) const
{
  for (auto foundations_it : m_foundations) {
    if(foundations_it->GetId() == id) {
      return foundations_it;
    }
  }
  return NULL;
}

Foundation* PileSet::GetFoundation(const Suit* suit)
{
  assert(suit);
  for (auto foundations_it : m_foundations) {
    if((*(foundations_it->GetSuit())) == *suit) {
      return foundations_it;
    }
  }
  return NULL;
}

uint8_t PileSet::CardAmountInBiggerTableau()
{
  uint8_t higher_size = 0;
  for (auto tableaus_it : m_tableaus) {
    if(((tableaus_it->Size())) > higher_size) {
      higher_size = tableaus_it->Size();
    }
  }
  return higher_size;
}
