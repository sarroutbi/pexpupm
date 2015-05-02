#ifndef PILESET_H
#define PILESET_H

#include <string>
#include <vector>

#include "Movement.h"
#include "Pile.h"

class PileSet 
{
public:
  PileSet();
  ~PileSet();
  bool AllFoundationsFull();
private:
  std::vector<Pile*> m_foundations;
  std::vector<Pile*> m_tableaus;
  Pile* m_deck;
  Pile* m_waste;
};

#endif // PILESET_H
