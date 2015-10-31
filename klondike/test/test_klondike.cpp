#include "FrenchDeckBuilder.h"
#include "gtest/gtest.h"

TEST(FrenchDeckBuilder, klondike)
{
  DeckBuilder* builder = new FrenchDeckBuilder;
  Deck deck;
  builder->CreateInitialDeck(&deck);
  EXPECT_EQ(deck.Size(), 52);
  delete builder;
}

TEST(FrenchDeckBuilderSize, klondike)
{
  DeckBuilder* builder = new FrenchDeckBuilder;
  Deck deck;
  builder->CreateInitialDeck(&deck);
  Card* card = NULL;
  while((card = deck.Pop())) {
    EXPECT_GE(card->GetNumber(), 1);
    EXPECT_LE(card->GetNumber(), 13);
  }

  delete builder;
}
