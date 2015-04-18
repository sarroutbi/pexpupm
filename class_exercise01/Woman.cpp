#include "Woman.h"

Woman::Woman()
{
  ;
}

Woman::~Woman()
{
  ;
}

void Woman::greet(Man* man)
{
  kiss(2);
}

void Woman::greet(Woman* man)
{
  lookBad();
}
