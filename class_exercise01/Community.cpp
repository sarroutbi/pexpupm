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
  Person* man1 = new Man();
  Person* man2 = new Man();
  Person* woman1 = new Woman();
  Person* woman2 = new Woman();
  m_persons.push_back(man1);
  m_persons.push_back(man2);
  m_persons.push_back(woman1);
  m_persons.push_back(woman2);
}

void Community::greetAll()
{
  uint32_t person1;
  uint32_t person2;
  for(person1 = 0; person1 < m_persons.size(); person1++) {
    for(person2 = person1; person2 < m_persons.size(); person2++) {
      Presenter p;
      p.present(m_persons[person1], m_persons[person2]);
    }
  }
}
