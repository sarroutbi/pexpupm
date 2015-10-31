#ifndef GOAL_H
#define GOAL_H

#include <string>
#include <vector>

#include "BoardLayout.h"

/**
  * class Goal
  * 
  */

class Goal
{
public:
  Goal ();
  ~Goal ();
  bool CheckSuccess (const BoardLayout& layout) const { return layout.GameFinished(); };
protected:
private:
};

#endif // GOAL_H
