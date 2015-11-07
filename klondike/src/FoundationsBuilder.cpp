#include <assert.h>
#include "FoundationsBuilder.h"
#include "FrenchFoundationsCreator.h"

FoundationsBuilder::FoundationsBuilder(e_board_type type)
  : m_board_type(type)
{
  m_foundations_creator[BOARD_TYPE_FRENCH] = new FrenchFoundationsCreator;
  assert(m_foundations_creator[m_board_type]);
}

FoundationsBuilder::~FoundationsBuilder()
{
  for (auto creator_it : m_foundations_creator) {
    delete creator_it.second;
  }
}

void
FoundationsBuilder::SetFoundations(std::vector<Foundation*>& foundations)
{
  m_foundations_creator[m_board_type]->CreateFoundations(foundations);
}
