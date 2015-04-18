#ifndef __MAN__
#define __MAN__

#include "Person.h"

class Woman;

class Man : public Person
{
public:
  Man(const std::string& name);
  ~Man();
  virtual void greet(Person* man);
  virtual void greet(const Man& man);
  virtual void greet(const Woman& woman);
};

#endif // __MAN__
