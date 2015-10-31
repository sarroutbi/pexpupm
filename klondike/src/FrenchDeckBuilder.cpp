#include <assert.h>
#include <iostream>
#include "FrenchDeckBuilder.h"
#include "FrenchSuit.h"
#include "Card.h"

FrenchDeckBuilder::FrenchDeckBuilder ()
{
  ;
}

FrenchDeckBuilder::~FrenchDeckBuilder ()
{
  ;
}

void FrenchDeckBuilder::CreateInitialDeck(Deck* deck)
{
  assert(deck);
  std::list<Suit> suit_list;
  CreateSuitList(suit_list);
  uint8_t number = 1;
  for(auto suit_it : suit_list) {
    for (; number <= MAX_CARD_NUMBER; number++) {
      Card* card = new Card(suit_it, number);
      deck->Push(card);
    }
    number = 1;
  }
}

void FrenchDeckBuilder::CreateSuitList(std::list<Suit>& suit_list)
{
  suit_list.push_back(FrenchSuit(SUIT_HEARTS));
  suit_list.push_back(FrenchSuit(SUIT_CLUBS));
  suit_list.push_back(FrenchSuit(SUIT_DIAMONDS));
  suit_list.push_back(FrenchSuit(SUIT_SPADES));
}
