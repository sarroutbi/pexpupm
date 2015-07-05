#ifndef DECK_H
#define DECK_H

#include <string>
#include <vector>
#include <stdint.h>

#include "Waste.h"
#include "Pile.h"
#include "Card.h"
#include "DeckBuilder.h"


class Deck : public Pile
{
public:

  Deck ();
  ~Deck ();
  virtual bool push(Card* card);
  virtual Card* pop (Card* card);
  virtual bool full() const;
  void reset();
  void setBuilder(DeckBuilder* builder);
private:
  DeckBuilder* m_deck_builder;
  uint32_t m_initial_size;
};

#endif // DECK_H
