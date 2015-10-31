#include "PlayerView.h"
#include <assert.h>
#include "TextInterface.h"

PlayerView::PlayerView ()
{
  m_interface = new TextInterface;
}

PlayerView::~PlayerView ()
{
  delete m_interface;
}

bool PlayerView::Draw (BoardLayout* layout)
{
  assert(layout);
  m_interface->Draw(*layout);
}

GameAction* PlayerView::GetPlayerAction() 
{
  GameAction* action = m_interface->GetPlayerAction();
  return action;
}
