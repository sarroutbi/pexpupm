#ifndef __PERSON__
#define __PERSON__

#include <stdint.h>
#include <string>

class Man;
class Woman;

class Person 
{
 public:
  Person(const std::string& name);
  ~Person();
  const std::string& getName() {return m_name;};
  void handleHand();
  void kiss(uint32_t number);
  void lookBad();
  void greetLog(Person* person);
  virtual void greet(Person* man) = 0;
  virtual void greet(const Man& man) = 0;
  virtual void greet(const Woman& woman) = 0;
 protected:
  std::string m_name;
};

#endif //__PERSON__
