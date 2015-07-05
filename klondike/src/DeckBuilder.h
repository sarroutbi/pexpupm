#ifndef DECK_BUILDER_H
#define DECK_BUILDER_H

class Deck;

class DeckBuilder
{
public:
  DeckBuilder ();
  virtual ~DeckBuilder ();
  virtual void createInitialDeck(Deck* deck) = 0;
};

#endif // DECK_BUILDER_H
