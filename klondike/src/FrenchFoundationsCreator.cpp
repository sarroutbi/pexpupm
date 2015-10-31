#include "FrenchFoundationsCreator.h"
#include "FrenchSuit.h"
#include "Foundation.h"

// QUIT
#include <iostream>

FrenchFoundationsCreator::FrenchFoundationsCreator()
{

}

FrenchFoundationsCreator::~FrenchFoundationsCreator()
{

}

void
FrenchFoundationsCreator::CreateFoundations(std::vector<Pile*>& foundations) const
{
  Pile* hearts = new Foundation(FrenchSuit(SUIT_HEARTS));
  Pile* clubs  = new Foundation(FrenchSuit(SUIT_CLUBS));
  Pile* diamonds = new Foundation(FrenchSuit(SUIT_DIAMONDS));
  Pile* spades = new Foundation(FrenchSuit(SUIT_SPADES));
  foundations.push_back(hearts);
  foundations.push_back(clubs);
  foundations.push_back(diamonds);
  foundations.push_back(spades);
}
