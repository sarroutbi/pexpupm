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
  virtual bool push(Card* card);
  virtual Card* pop ();
  virtual bool full() const;
private:
  uint32_t m_full_size;
};

#endif // WASTE_H
