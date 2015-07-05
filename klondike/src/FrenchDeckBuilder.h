#ifndef FRENCH_DECK_BUILDER_H
#define FRENCH_DECK_BUILDER_H

class FrenchDeckBuilder : public DeckBuilder
{
public:
  FrenchDeckBuilder ();
  ~FrenchDeckBuilder ();
  void createInitialDeck(Deck* deck);
};

#endif // DECK_BUILDER_H
