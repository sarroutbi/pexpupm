#include <assert.h>
#include <iostream>
#include "Man.h"

Man::Man(const std::string& name) : Person(name)
{

}

Man::~Man()
{

}

void Man::greet(Person* person)
{
  assert(person);
  std::cout << getName() << " "; 
  person->greet(*this); 
  std::cout << " a " << person->getName();
  std::cout << std::endl;
}

void Man::greet(const Man& man)
{
  handleHand();
}

void Man::greet(const Woman& woman)
{
  kiss(2);
}
