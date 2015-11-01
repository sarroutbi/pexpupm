#include "FrenchFoundationsCreator.h"
#include "FrenchSuit.h"
#include "Foundation.h"

FrenchFoundationsCreator::FrenchFoundationsCreator()
{

}

FrenchFoundationsCreator::~FrenchFoundationsCreator()
{

}

void
FrenchFoundationsCreator::CreateFoundations(std::vector<Foundation*>& foundations) const
{
  Foundation* hearts = new Foundation(new FrenchSuit(SUIT_HEARTS));
  Foundation* clubs  = new Foundation(new FrenchSuit(SUIT_CLUBS));
  Foundation* diamonds = new Foundation(new FrenchSuit(SUIT_DIAMONDS));
  Foundation* spades = new Foundation(new FrenchSuit(SUIT_SPADES));
  foundations.push_back(hearts);
  foundations.push_back(clubs);
  foundations.push_back(diamonds);
  foundations.push_back(spades);
}
