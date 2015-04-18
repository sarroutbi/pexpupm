#ifndef __PERSON__
#define __PERSON__

#include <stdint.h>

class Person 
{
 public:
  Person();
  ~Person();
  void handleHand();
  void kiss(uint8_t number);
  void lookBad();
  virtual void greet(Person* p);
};

#endif //__PERSON__
