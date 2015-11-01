#ifndef WASTE_TO_FOUNDATION_H
#define WASTE_TO_FOUNDATION_H

#include "Movement.h"

class WasteToFoundation : public Movement
{
public:

  WasteToFoundation();
  ~WasteToFoundation();
  virtual bool PerformMovement(BoardLayout* layout);
  virtual std::string ToString () const;
};

#endif // MOVEMENT_H
