#include <assert.h>
#include "Game.h"

Game::Game ()
{

}

Game::~Game ()
{

}


void Game::Init ()
{
  StartGame();
  MainLoop();
}


void Game::StartGame ()
{
  m_layout.ResetPiles();
}


void Game::MainLoop ()
{
  GameAction* action = NULL;
  while (!m_goal.CheckSuccess(m_layout)) {
    m_view.Draw(&m_layout);
    action = m_view.GetPlayerAction();
    if(action) {
      ProcessAction(action);
    }
  }
  Init();
}

void Game::ProcessAction(GameAction* action)
{
  assert(action);
  action->PerformAction(&m_layout);
  delete action;
}
