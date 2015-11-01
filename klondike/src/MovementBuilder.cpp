#include "MovementBuilder.h"
#include "DeckToWaste.h"
#include "WasteToFoundation.h"

MovementBuilder::MovementBuilder()
{
  Movement* deck_to_waste = new DeckToWaste;
  Movement* waste_to_foundation = new WasteToFoundation;
  m_movement_list.push_back(deck_to_waste);
  m_movement_list.push_back(waste_to_foundation);
}

MovementBuilder::~MovementBuilder()
{
  m_movement_list.clear();
}

std::vector<Movement*>* MovementBuilder::GetMovementList()
{
  return &m_movement_list;
}

Movement* MovementBuilder::GetMovementWithId(const uint8_t& id)
{
  Movement* movement = NULL;
  for (auto move_it : m_movement_list) {
    if(move_it->GetId() == id) {
      movement = move_it;
    }
  }
  return movement;
}
