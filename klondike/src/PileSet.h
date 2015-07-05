#ifndef PILESET_H
#define PILESET_H

#include <string>
#include <vector>

#include "Movement.h"
#include "Pile.h"
#include "Deck.h"
#include "Pile.h"

class PileSet 
{
public:
  PileSet();
  ~PileSet();
  bool allFoundationsFull();
  virtual bool resetPiles();
  Pile* getDeck();
  Pile* getWaste();
private:
  bool resetFoundations();
  bool resetTableaus();
  std::vector<Pile*> m_foundations;
  std::vector<Pile*> m_tableaus;
  Deck* m_deck;
  Waste* m_waste;
};

#endif // PILESET_H
