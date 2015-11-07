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
  for(auto suit_it : m_suit_list) {
    delete suit_it;
  }
  m_suit_list.clear();
}

void FrenchDeckBuilder::CreateInitialDeck(Deck* deck)
{
  assert(deck);
  deck->Clean();
  CreateSuitList();
  uint8_t number = MAX_CARD_NUMBER;
  for(auto suit_it : m_suit_list) {
    for (; number >= 1; number--) {
      Card* card = new Card(suit_it, number);
      if(number == MAX_CARD_NUMBER) {
        card->SetHigher();
      }
      deck->Push(card);
    }
    number = MAX_CARD_NUMBER;
  }
}

void FrenchDeckBuilder::CreateSuitList()
{
  m_suit_list.clear();
  m_suit_list.push_back(new FrenchSuit(SUIT_HEARTS));
  m_suit_list.push_back(new FrenchSuit(SUIT_CLUBS));
  m_suit_list.push_back(new FrenchSuit(SUIT_DIAMONDS));
  m_suit_list.push_back(new FrenchSuit(SUIT_SPADES));
}
