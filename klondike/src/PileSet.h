#ifndef PILESET_H
#define PILESET_H

#include <string>
#include <vector>

#include "Movement.h"
#include "Pile.h"
#include "Deck.h"
#include "FoundationsBuilder.h"

class PileSet
{
public:
  PileSet(FoundationsBuilder* pile_builder,
          DeckBuilder* deck_builder);
  ~PileSet();
  bool AllFoundationsFull() const;
  virtual bool ResetPiles();
  Deck* GetDeck() { return m_deck; }
  Waste* GetWaste() { return m_waste; }
private:
  bool ResetFoundations();
  bool ResetTableaus();
  std::vector<Pile*> m_foundations;
  std::vector<Pile*> m_tableaus;
  Deck* m_deck;
  Waste* m_waste;
  FoundationsBuilder* m_foundations_builder;
  DeckBuilder* m_deck_builder;
};

#endif // PILESET_H
