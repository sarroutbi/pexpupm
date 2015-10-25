#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <string>
#include <vector>
#include <assert.h>

#include "BoardLayout.h"
#include "Movement.h"
#include "DealMode.h"
#include "GameAction.h"

class PlayerView
{
public:
  PlayerView ();
  virtual ~PlayerView ();
  bool Draw (BoardLayout* layout)
  {
    assert(layout);
  }
  GameAction* GetPlayerAction() 
  {
    GameAction* action = NULL;
    return action;
  }
};

#endif // PLAYERVIEW_H
