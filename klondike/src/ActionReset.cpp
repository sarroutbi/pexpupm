#include <assert.h>
#include "ActionReset.h"

ActionReset::ActionReset()
{

}

ActionReset::~ActionReset()
{

}

void ActionReset::PerformAction(BoardLayout* layout) const
{
  assert(layout);
  layout->ResetPiles();
}
