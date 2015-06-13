#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <stdint.h>
#include <string>
#include <vector>

#include "Suite.h"
#include "Pile.h"

const uint8_t MAX_FOUNDATION_CARDS = 13;

class Foundation : public Pile
{
public:
  Foundation (const Suite& suite,
              const unsigned int max_cards = MAX_FOUNDATION_CARDS);
  ~Foundation ();
  virtual const bool Full () const;
protected:
private:
  unsigned int m_max_cards;
  Suite m_suite;
};

#endif // FOUNDATION_H
