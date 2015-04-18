#include <iostream>
#include "Community.h"
#include "Man.h"
#include "Woman.h"
#include "Presenter.h"

Community::Community()
{

}

Community::~Community()
{

}

void Community::init()
{
  createCommunity();
  greetAll();
}

void Community::createCommunity()
{
  // This could be more random
  Man* man1 = new Man("Luis");
  Man* man2 = new Man("Pedro");
  Woman* woman1 = new Woman("Jenny");
  Woman* woman2 = new Woman("Wendy");
  m_persons.push_back(man1);
  m_persons.push_back(man2);
  m_persons.push_back(woman1);
  m_persons.push_back(woman2);
}

void Community::greetAll()
{
  uint32_t person1;
  uint32_t person2;

  for(person1 = 0; person1 < (m_persons.size()-1); person1++) {
    for(person2 = person1+1; person2 < m_persons.size(); person2++) {

      m_persons[person1]->greet(m_persons[person2]);
    }
  }
}
