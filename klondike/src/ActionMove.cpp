#include <assert.h>
#include "ActionMove.h"

// QUIT 
#include <iostream>
#include <unistd.h>

ActionMove::ActionMove(Movement* movement) : m_movement(movement)
{

}

ActionMove::ActionMove() : m_movement(NULL)
{

}

ActionMove::~ActionMove()
{
  ;
}

void ActionMove::PerformAction(BoardLayout* layout) const
{
  assert(layout);
  assert(m_movement);
  m_movement->PerformMovement(layout);

  // QUIT 
  // PileSet* pile = layout->GetPileSet();
  // Deck* deck = pile->GetDeck();
  // Waste* waste = pile->GetWaste();
  // std::cout << "Deck  Size:" << std::to_string(deck->Size()) << std::endl;
  // std::cout << "Waste Size:" << std::to_string(waste->Size()) << std::endl;
  // if(waste->TopCard()) {
  //   std::cout << "Waste Top Card:" << 
  //     waste->TopCard()->ToShortString() << std::endl;
  // }
  // if(waste->BottomCard()) {
  //   std::cout << "Waste Bottom Card:" <<
  //     waste->BottomCard()->ToShortString() << std::endl;
  // }
  // std::cout << "Deck:" << deck->ToShortString();
  // std::cout << std::endl;
  // std::cout << "Waste:" << waste->ToShortString();
  // std::cout << std::endl;
  // sleep(1);
  // std::cout << std::endl;
}
