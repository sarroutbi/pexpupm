#ifndef WASTE_H
#define WASTE_H

#include "Pile.h"

#include <string>
#include <vector>
#include <stdint.h>

/**
  * class Waste
  * 
  */
class Waste : public Pile
{
public:
  Waste ();
  ~Waste ();
  virtual bool Push(Card* card);
  virtual Card* Pop ();
  virtual bool Full() const;
private:
  uint32_t m_full_size;
};

#endif // WASTE_H
