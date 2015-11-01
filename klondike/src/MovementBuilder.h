#ifndef MOVEMENT_BUILDER
#define MOVEMENT_BUILDER

#include "Movement.h"

class MovementBuilder
{
public:
  MovementBuilder();
  ~MovementBuilder();
  std::vector<Movement*>* GetMovementList();
  Movement* GetMovementWithId(const uint8_t& id);
private:
  std::vector<Movement*> m_movement_list;
};

#endif // MOVEMENT_BUILDER
