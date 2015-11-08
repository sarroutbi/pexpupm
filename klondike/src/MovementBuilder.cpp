#include "MovementBuilder.h"
#include "DeckToWaste.h"
#include "WasteToFoundation.h"
#include "WasteToTableau.h"
#include "TableauToFoundation.h"
#include "FoundationToTableau.h"

MovementBuilder::MovementBuilder()
{
  Movement* deck_to_waste = new DeckToWaste;
  Movement* waste_to_foundation = new WasteToFoundation;
  Movement* waste_to_tableau = new WasteToTableau;
  Movement* tableau_to_foundation = new TableauToFoundation;
  Movement* foundation_to_tableau = new FoundationToTableau;
  
  m_movement_list.push_back(deck_to_waste);
  m_movement_list.push_back(waste_to_foundation);
  m_movement_list.push_back(waste_to_tableau);
  m_movement_list.push_back(tableau_to_foundation);
  m_movement_list.push_back(foundation_to_tableau);
}

MovementBuilder::~MovementBuilder()
{
  for (auto movement : m_movement_list) {
    delete movement;
  }
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
