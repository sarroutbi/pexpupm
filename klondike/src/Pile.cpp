#include "Pile.h"

// Constructors/Destructors
//  

Pile::Pile () : m_card_pile()
{
  ;
}

Pile::~Pile ()
{ 
  ;
}

void Pile::clean ()
{
  m_card_pile.clear();
}
