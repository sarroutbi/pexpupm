#include <stdlib.h>
#include <assert.h>
#include "ActionExit.h"
ActionExit::ActionExit()
{

}

ActionExit::~ActionExit()
{

}

void ActionExit::PerformAction(BoardLayout* layout) const
{
  assert(layout);
  layout->SetGameFinished();
}
