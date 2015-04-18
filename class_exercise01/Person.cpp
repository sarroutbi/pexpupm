#include <assert.h>
#include <iostream>
#include <sstream>
#include "Person.h"

Person::Person(const std::string& name) : m_name(name)
{
  ;
}

Person::~Person()
{
  ;
}

void Person::handleHand()
{
  std::cout << "estrecha las manos";
}

void Person::lookBad()
{
  std::cout << "mira mal";
}

void Person::kiss(uint32_t number)
{
  std::ostringstream oss;
  oss << number;
  std::cout << "besa con (" << oss.str() << ") besos";
}

void Person::greetLog(Person* person)
{
  assert(person);
  std::cout << "Persona:" << getName() <<
  " saluda a:" << person->getName() << " con:";
  person->greet(this);
  std::cout << std::endl;
}
