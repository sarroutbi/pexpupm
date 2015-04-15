#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "Goal.h"
#include "Board.h"
#include "PlayerView.h"
#include "DealMode.h"
#include "BoardLayout.h"

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
  Board m_board;
  PlayerView m_playerview;
  DealMode m_dealmode;
};

#endif // GAME_H
