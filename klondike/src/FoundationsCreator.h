#ifndef FOUNDATIONS_CREATOR
#define FOUNDATIONS_CREATOR

#include <vector>
#include "Pile.h"

class FoundationsCreator
{
 public:
  FoundationsCreator()  {};
  virtual ~FoundationsCreator() {};
  virtual void CreateFoundations(std::vector<Pile*>& foundations) const = 0;
};

#endif // FOUNDATIONS_CREATOR
