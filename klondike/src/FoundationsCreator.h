#ifndef FOUNDATIONS_CREATOR
#define FOUNDATIONS_CREATOR

#include <vector>
#include "Foundation.h"

class FoundationsCreator
{
 public:
  FoundationsCreator()  {};
  virtual ~FoundationsCreator() {};
  virtual void CreateFoundations(std::vector<Foundation*>& foundations) const = 0;
};

#endif // FOUNDATIONS_CREATOR
