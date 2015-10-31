#include <assert.h>
#include <vector>
#include "PileSet.h"
#include "Foundation.h"
#include "Deck.h"
#include "Waste.h"

PileSet::PileSet(FoundationsBuilder* foundations_builder) :
  m_foundations(), m_tableaus(), m_deck(NULL), m_waste(NULL)
{
  assert(foundations_builder);
  foundations_builder->setFoundations(m_foundations);
  m_deck = new Deck();
  m_waste = new Waste();
}

PileSet::~PileSet()
{
  delete m_deck;
  delete m_waste;
}

bool PileSet::allFoundationsFull()
{
  assert(m_foundations.size() != 0);
  std::vector<Pile*>::const_iterator it;
  for (it = m_foundations.begin(); it != m_foundations.end(); it++) {
    if(!((*it)->Full())) {
      return false;
    }
  }
  return true;
}

bool PileSet::resetPiles()
{
  resetFoundations();
  resetTableaus();
  m_deck->Reset();
  m_waste->Clean();
}

bool PileSet::resetFoundations()
{
  std::vector<Pile*>::iterator it = m_foundations.begin();
  while (it++ != m_foundations.end()) {
    (*it)->Clean();
    m_foundations.erase(it);
  }
}

bool PileSet::resetTableaus()
{
  std::vector<Pile*>::iterator it = m_tableaus.begin();
  while (it++ != m_tableaus.end()) {
    (*it)->Clean();
    m_tableaus.erase(it);
  }
}
