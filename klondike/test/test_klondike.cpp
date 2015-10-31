#include "FrenchDeckBuilder.h"
#include "gtest/gtest.h"

TEST(FrenchDeckBuilderSize, klondike)
{
  DeckBuilder* builder = new FrenchDeckBuilder;
  Deck deck;
  builder->CreateInitialDeck(&deck);
  EXPECT_EQ(deck.Size(), 52);
  delete builder;
}

TEST(FrenchDeckBuilderNumber, klondike)
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

TEST(FrenchDeckBuilderTurned, klondike)
{
  DeckBuilder* builder = new FrenchDeckBuilder;
  Deck deck;
  builder->CreateInitialDeck(&deck);
  Card* card = NULL;
  while((card = deck.Pop())) {
    EXPECT_TRUE(card->isTurnedDown());
  }

  delete builder;
}
