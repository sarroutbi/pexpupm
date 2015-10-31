#ifndef FRENCH_DECK_BUILDER_H
#define FRENCH_DECK_BUILDER_H

#include "Deck.h"
#include "DeckBuilder.h"

class FrenchDeckBuilder : public DeckBuilder
{
public:
  FrenchDeckBuilder ();
  ~FrenchDeckBuilder ();
  virtual void CreateInitialDeck(Deck* deck);
  virtual void CreateSuitList(std::list<Suit>& suit);
private:
  static const uint8_t MAX_CARD_NUMBER = 13;
};

#endif // FRENCH_DECK_BUILDER_H
