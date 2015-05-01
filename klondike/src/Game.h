#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "Goal.h"
#include "Board.h"
#include "PlayerView.h"
#include "DealMode.h"
#include "BoardLayout.h"
#include "GameAction.h"
#include "GameActionReset.h"
#include "GameActionExit.h"
#include "GameActionMovement.h"

/**
  * class Game
  * 
  */
class Game
{
public:

  // Constructors/Destructors
  //  
  /**
   * Empty Constructor
   */
  Game ();

  /**
   * Empty Destructor
   */
  ~Game ();

  void ProcessAction(GameAction* action);

  /**
   */
  void Init ();

  /**
   */
  void StartGame ();

  /**
   */
  void MainLoop ();

private:
  Goal m_goal;
  PlayerView m_view;
  BoardLayout m_layout;
};

#endif // GAME_H
