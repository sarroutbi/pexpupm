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
  Foundation* hearts = new Foundation(0, new FrenchSuit(SUIT_HEARTS));
  Foundation* clubs  = new Foundation(1, new FrenchSuit(SUIT_CLUBS));
  Foundation* diamonds = new Foundation(2, new FrenchSuit(SUIT_DIAMONDS));
  Foundation* spades = new Foundation(3, new FrenchSuit(SUIT_SPADES));
  foundations.push_back(hearts);
  foundations.push_back(clubs);
  foundations.push_back(diamonds);
  foundations.push_back(spades);
}
