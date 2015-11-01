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
  virtual bool Push(Card* card);
  virtual Card* Pop ();
  virtual bool Full() const;
  void Reset();
  void SetBuilder(DeckBuilder* builder);
  void Shuffle();
private:
  int RandomFunction (int seed);
  uint32_t m_initial_size;
};

#endif // DECK_H
