#include <vector>
#include "Person.h"

class Community 
{
 public:
  Community();
  ~Community();
  void init();
  void createCommunity();
  void greetAll();
 private:
  std::vector<Person*> m_persons;
};
