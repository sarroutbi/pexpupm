#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <string>
#include <vector>

#include "Suite.h"
#include "Pile.h"

/**
  * class Foundation
  * 
  */

class Foundation : public Pile
{
public:

  /**
   * Empty Constructor
   */
  Foundation (const Suite& suite,
              const unsigned int max_cards);

  /**
   * Empty Destructor
   */
  ~Foundation ();
  
  /**
   * Check if foundation is completed
   */
  const bool Completed () const;

protected:

private:
  unsigned int m_max_cards;
  Suite m_suite;
};

#endif // FOUNDATION_H
