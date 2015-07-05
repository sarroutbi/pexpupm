#include <vector>
#include "PileSet.h"
#include "Foundation.h"
#include "Deck.h"
#include "Waste.h"

PileSet::PileSet() : m_foundations(), m_tableaus(),
  m_deck(NULL), m_waste(NULL)
{
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
  std::vector<Pile*>::const_iterator it;
  for (it = m_foundations.begin(); it != m_foundations.end(); it++) {
    if(!((*it)->full())) {
      return false;
    }
  }
  return true;
}

bool PileSet::resetPiles()
{
  resetFoundations();
  resetTableaus();
  m_deck->reset();
  m_waste->clean();
}

bool PileSet::resetFoundations()
{
  std::vector<Pile*>::iterator it = m_foundations.begin();
  while (it++ != m_foundations.end()) {
    (*it)->clean();
    m_foundations.erase(it);
  }
}

bool PileSet::resetTableaus()
{
  std::vector<Pile*>::iterator it = m_tableaus.begin();
  while (it++ != m_tableaus.end()) {
    (*it)->clean();
    m_tableaus.erase(it);
  }
}
