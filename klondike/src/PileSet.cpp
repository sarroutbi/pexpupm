#include <assert.h>
#include <vector>

#include "PileSet.h"
#include "Foundation.h"
#include "Deck.h"
#include "Waste.h"

PileSet::PileSet(FoundationsBuilder* foundations_builder,
                 DeckBuilder* deck_builder) :
  m_foundations(), m_tableaus(), m_deck(NULL), m_waste(NULL),
  m_foundations_builder(foundations_builder),
  m_deck_builder(deck_builder)
{
  assert(m_foundations_builder);
  assert(m_deck_builder);
  m_deck = new Deck();
  m_waste = new Waste();
  m_foundations_builder->SetFoundations(m_foundations);
  m_deck_builder->CreateInitialDeck(m_deck);
}

PileSet::~PileSet()
{
  assert(0);
  delete m_deck;
  delete m_waste;
  delete m_foundations_builder;
  delete m_deck_builder;
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
}

bool PileSet::ResetFoundations()
{
  std::vector<Foundation*>::iterator it = m_foundations.begin();
  for (; it != m_foundations.end(); it++) {
    if(!((*it)->Full())) {
      (*it)->Clean();
    }
  }
}

bool PileSet::ResetTableaus()
{
  std::vector<Tableau*>::iterator it = m_tableaus.begin();
  for (; it != m_tableaus.end(); it++) {
    (*it)->Clean();
    m_tableaus.erase(it);
  }
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
