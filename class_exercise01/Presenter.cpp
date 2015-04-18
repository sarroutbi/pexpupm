#include <assert.h>
#include "Presenter.h"
#include "Person.h"

Presenter::Presenter()
{
  ;
}

Presenter::~Presenter()
{
  ;
}

void Presenter::present(Person* p1, Person* p2)
{
  assert(p1);
  assert(p2);
  p1->greet(p2);
};
