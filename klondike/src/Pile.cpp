#include "Pile.h"

Pile::Pile () : m_card_pile()
{
  ;
}

Pile::~Pile ()
{ 
  ;
}

void Pile::Clean ()
{
  m_card_pile.clear();
}
