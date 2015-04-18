#include <assert.h>
#include <iostream>
#include "Person.h"

Person::Person()
{

}

Person::~Person()
{

}

void Person::handleHand()
{
  std::cout << "estrecha las manos";
}

void Person::lookBad()
{
  std::cout << "mira mal";
}

void Person::kiss(uint8_t number)
{
  std::cout << "besa con (" << number << ") besos";
}

void Person::greet(Person* person)
{
  assert(person);
  std::cout << "Persona:" << person->getName() << " saluda con:" << person->greet();
}
