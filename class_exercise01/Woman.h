#ifndef __WOMAN__
#define __WOMAN__

#include "Man.h"

class Man;

class Woman : public Person
{
public:
  Woman();
  ~Woman();
  void greet(Man* man);
  void greet(Woman* woman);
};

#endif // __WOMAN__
