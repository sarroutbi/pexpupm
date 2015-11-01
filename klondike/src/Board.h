#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "Movement.h"
#include "BoardLayout.h"


class Board
{
public:

  Board ();
  virtual ~Board ();
  bool Move (const Movement& movement);
  BoardLayout GetLayout ();
};

#endif // BOARD_H
