#include "FrenchDeckBuilder.h"
#include "TableausBuilder.h"
#include "BoardLayout.h"
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
  uint8_t card_amount = deck.Size();
  uint8_t card_counter = 0;
  while((card = deck.CardAt(card_counter))) {
    EXPECT_GE(card->GetNumber(), 1);
    EXPECT_LE(card->GetNumber(), 13);
    card_counter--;
  }

  delete builder;
}

TEST(FrenchDeckBuilderTurned, klondike)
{
  DeckBuilder* builder = new FrenchDeckBuilder;
  Deck deck;
  builder->CreateInitialDeck(&deck);
  Card* card = NULL;
  uint8_t card_amount = deck.Size();
  uint8_t card_counter = 0;
  while((card = deck.CardAt(card_counter))) {
    EXPECT_TRUE(card->IsTurnedDown());
    card_counter++;
  }
  delete builder;
}

TEST(TableausBuilderNumber, klondike)
{
  TableausBuilder* tableau_builder = new TableausBuilder(7);
  DeckBuilder* deck_builder = new FrenchDeckBuilder;
  PileSet* pile_set = new PileSet(new FoundationsBuilder(BOARD_TYPE_FRENCH), deck_builder,
                                  tableau_builder);
  EXPECT_EQ(pile_set->GetTableaus()->size(), 7);
  delete pile_set;
}

TEST(TableausBuilderCardNumber, klondike)
{
  uint8_t tableau_counter = 0;
  uint8_t tableau_number = 8;
  TableausBuilder* tableau_builder = new TableausBuilder(tableau_number);
  DeckBuilder* deck_builder = new FrenchDeckBuilder;
  PileSet pile_set(new FoundationsBuilder(BOARD_TYPE_FRENCH), deck_builder, tableau_builder);
  std::vector<Tableau*>* tableaus = pile_set.GetTableaus();
  EXPECT_TRUE(tableaus != nullptr);
  for (tableau_counter = 0; tableau_counter < tableau_number; tableau_counter++) {
    EXPECT_TRUE(((*tableaus)[tableau_counter])->Size() == tableau_counter+1);
  }
}

