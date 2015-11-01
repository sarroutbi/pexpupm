#ifndef DECK_TO_WASTE_H
#define DECK_TO_WASTE_H

#include "Movement.h"

class DeckToWaste : public Movement
{
public:

 DeckToWaste();
  ~DeckToWaste();
  virtual bool PerformMovement(BoardLayout* layout);
  virtual std::string ToString () const;
};

#endif // MOVEMENT_H
