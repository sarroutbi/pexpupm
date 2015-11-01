#include <assert.h>
#include "DeckToWaste.h"
#include "BoardLayout.h"

DeckToWaste::DeckToWaste() : Movement(1)
{
  ;
}
DeckToWaste::~DeckToWaste()
{
  ;
};

std::string DeckToWaste::ToString () const
{
  return "D->W";
}

bool DeckToWaste::PerformMovement(BoardLayout* layout)
{
  assert(layout);
  bool movement_performed;
  PileSet* pile_set = layout->GetPileSet();
  assert(pile_set);
  Deck* deck = pile_set->GetDeck();
  assert(deck);
  Waste* waste = pile_set->GetWaste();
  assert(deck);
  Card* card = NULL;

  if((deck->Size() == 0) && (waste->Size() == 0)) {
    movement_performed = false;
  }
  else if (deck->Size() == 0 && waste->Size() != 0) {
    while (card = waste->Pop()) {
      deck->Push(card);
    }
    movement_performed = true;
  }
  else if (deck->Size() != 0) {
    card = deck->Pop();
    waste->Push(card);
    movement_performed = true;
  }
  return movement_performed;
}
