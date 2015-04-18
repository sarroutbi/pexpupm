#include <assert.h>
#include <iostream>
#include "Woman.h"

Woman::Woman(const std::string& name) : Person(name)
{
  ;
}

Woman::~Woman()
{
  ;
}

void Woman::greet(Person* person)
{
  assert(person);
  std::cout << getName() << " "; 
  person->greet(*this); 
  std::cout << " a " << person->getName();
  std::cout << std::endl;
}

void Woman::greet(const Man& man)
{
  kiss(2);
}

void Woman::greet(const Woman& man)
{
  lookBad();
}
