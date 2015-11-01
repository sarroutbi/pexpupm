#ifndef FRENCH_FOUNDATIONS_CREATOR
#define FRENCH_FOUNDATIONS_CREATOR

#include "FoundationsCreator.h"

class FrenchFoundationsCreator : public FoundationsCreator
{
public:
  FrenchFoundationsCreator();
  ~FrenchFoundationsCreator();
  virtual void CreateFoundations(std::vector<Foundation*>& foundations) const;
};
#endif
