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
  virtual void CreateSuitList(std::list<Suit>& suit) = 0;
};

#endif // DECK_BUILDER_H
