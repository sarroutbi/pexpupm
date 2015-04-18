#include "Man.h"

Man::Man()
{

}

Man::~Man()
{

}

void Man::greet(Man* man)
{
  handleHand();
}

void Man::greet(Woman* woman)
{
  kiss(2);
}
