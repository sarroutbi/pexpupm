#ifndef ACTION_RESET_H
#define ACTION_RESET_H

#include "GameAction.h"

class ActionReset : public GameAction 
{
public:
  ActionReset()  ;
  ~ActionReset() ;
  virtual void PerformAction(BoardLayout* layout) const;
private:
};

#endif // ACTION_RESET
