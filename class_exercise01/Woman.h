#ifndef __WOMAN__
#define __WOMAN__

#include <string>
#include "Person.h"
#include "Man.h"

class Man;

class Woman : public Person
{
public:
  Woman(const std::string& name);
  ~Woman();
  virtual void greet(Person* person);
  virtual void greet(const Man& man);
  virtual void greet(const Woman& woman);
};

#endif // __WOMAN__
