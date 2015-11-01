#ifndef ACTION_EXIT_H
#define ACTION_EXIT_H

#include "GameAction.h"

class ActionExit : public GameAction
{
public:
  ActionExit()  ;
  ~ActionExit() ;
  virtual void PerformAction(BoardLayout* layout) const ;
private:
};

#endif // ACTION_EXIT
