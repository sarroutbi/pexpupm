#ifndef DECK_BUILDER_H
#define DECK_BUILDER_H

#include <list>
#include "Suit.h"

class Deck;

class DeckBuilder
{
public:
  DeckBuilder () {};
  virtual ~DeckBuilder () {};
  virtual void CreateInitialDeck(Deck* deck) = 0;
  virtual void CreateSuitList() = 0;
  virtual void CleanSuitList() = 0;
protected:
  std::list<Suit*> m_suit_list;
};

#endif // DECK_BUILDER_H
