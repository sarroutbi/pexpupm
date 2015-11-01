#include <assert.h>
#include "WasteToFoundation.h"
#include "BoardLayout.h"
#include "PileSet.h"

WasteToFoundation::WasteToFoundation() : Movement(2)
{
  ;
}

WasteToFoundation::~WasteToFoundation()
{
  ;
}

bool WasteToFoundation::PerformMovement(BoardLayout* layout)
{
  assert(layout);
  bool movement_performed;
  PileSet* pile_set = layout->GetPileSet();
  assert(pile_set);
  Waste* waste = pile_set->GetWaste();
  assert(waste);
  Card* card = NULL;

  if((waste->Size() == 0)) {
    movement_performed = false;
  }
  else {
    card = waste->Pop();
    Foundation* foundation = pile_set->GetFoundation(card->GetSuit());
    if(foundation->Push(card)) {
      movement_performed = true;
    }
    else {
      waste->Push(card);
      movement_performed = false;
    }
  }
  return movement_performed;
}

std::string WasteToFoundation::ToString () const
{
  return "W->F";
}
