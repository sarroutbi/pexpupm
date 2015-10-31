#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <string>
#include <vector>

#include "BoardLayout.h"
#include "Movement.h"
#include "DealMode.h"
#include "GameAction.h"
#include "Interface.h"

class PlayerView
{
public:
  PlayerView ();
  virtual ~PlayerView ();
  bool Draw(BoardLayout* layout);
  GameAction* GetPlayerAction();
private:
  Interface* m_interface;
};

#endif // PLAYERVIEW_H
