#ifndef __MAN__
#define __MAN__

#include "Person.h"
#include "Woman.h"

class Woman;

class Man : public Person
{
public:
  Man();
  ~Man();
  void greet(Man* man);
  void greet(Woman* woman);
};

#endif // __MAN__
