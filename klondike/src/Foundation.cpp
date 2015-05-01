#include "Foundation.h"

// Constructors/Destructors
//  

Foundation::Foundation (const Suite& suite, 
                        const unsigned int max_cards) :
m_suite(suite), m_max_cards(max_cards)
{
  ;
}

Foundation::~Foundation () 
{ 
  ;
}

const bool Foundation::Completed () const
{
  return m_card_pile.size() == m_max_cards;
}
