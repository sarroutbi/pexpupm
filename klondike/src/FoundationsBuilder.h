#ifndef FOUNDATIONS_BUILDER_H
#define FOUNDATIONS_BUILDER_H

#include "BoardTypes.h"
#include "Pile.h"
#include "FoundationsCreator.h"

#include <map>

class FoundationsBuilder
{
public:
 FoundationsBuilder(e_board_type type);
  ~FoundationsBuilder();
  void setFoundations(std::vector<Pile*>& foundations);
private:
  e_board_type m_board_type;
  std::map<e_board_type, FoundationsCreator*> m_foundations_creator;
};

#endif
