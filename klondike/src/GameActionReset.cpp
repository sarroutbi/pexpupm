#include "GameActionReset.h"

GameActionReset::GameActionReset()
{
  ;
}

GameActionReset::~GameActionReset()
{
  ;
}

void GameActionReset::PerformAction(BoardLayout& layout) const
{
  layout.ResetPiles();
}
