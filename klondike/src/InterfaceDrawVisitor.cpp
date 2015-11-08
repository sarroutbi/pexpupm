#include <assert.h>
#include "InterfaceDrawVisitor.h"
#include <iostream>
#include "TextInterface.h"

InterfaceDrawVisitor::InterfaceDrawVisitor()
{

}

InterfaceDrawVisitor::~InterfaceDrawVisitor()
{

}
 
void InterfaceDrawVisitor::visitTextInterface(TextInterface* text_interface) const
{
  assert(text_interface);
  PileSet* pile_set = text_interface->GetPileSet();
  assert(pile_set);
  DrawDeckWasteFoundationHeader(pile_set->GetFoundations());
  std::cout << "   ";
  Draw(pile_set->GetDeck());
  std::cout << "  ";
  Draw(pile_set->GetWaste());
  std::cout << "      ";
  Draw(pile_set->GetFoundations());
  std::cout << std::endl;
  std::cout << std::endl;
  Draw(pile_set->GetTableaus(), pile_set->CardAmountInBiggerTableau());
  std::cout << std::endl;
}

void InterfaceDrawVisitor::DrawDeckWasteFoundationHeader(std::vector<Foundation*>*
                                                         foundations) const
{
  std::cout << "[Deck][Waste]     ";
  for (auto foundation_it : *foundations) {
    std::cout.width(4);
    std::cout << "[Fd" << std::to_string(foundation_it->GetId()) << "]";
    std::cout.width(1);
  }
  std::cout << std::endl;
}


void InterfaceDrawVisitor::Draw(Deck* deck) const
{
  assert(deck);
  if(deck->Size() == 0) {
    std::cout << "[ ]";
  }
  else {
    std::cout << "[X]";
  }
}

void InterfaceDrawVisitor::Draw(Waste* waste) const
{
  assert(waste);
  if(waste->Size() > 0) {
    std::cout << "[";
    std::cout.width(3);
    std::cout << waste->TopCard()->ToShortString();
    std::cout << "]";
    std::cout.width(1);
  }
  else {
    std::cout << "[   ]";
  }
}

void InterfaceDrawVisitor::Draw(std::vector<Foundation*>* foundations) const
{
  assert(foundations);
  for (auto foundations_it : *foundations) {
    if(foundations_it->Size() > 0) {
      std::cout << "[";
      std::cout.width(3);
      std::cout << foundations_it->TopCard()->ToShortString();
      std::cout << "]";
      std::cout.width(1);
    }
    else {
      std::cout << "[   ]";
    }
    std::cout << " ";
  }
}

void InterfaceDrawVisitor::DrawTableausIds(std::vector<Tableau*>* tableaus) const
{
  assert(tableaus);
  for (auto tableau_it : *tableaus) {
    std::cout.width(4);
    std::cout << "[Tb" << std::to_string(tableau_it->GetId()) << "]";
    std::cout.width(1);
  }
  std::cout << std::endl;
}

void InterfaceDrawVisitor::DrawTableausInLine(std::vector<Tableau*>* tableaus,
                                              const uint8_t& line) const
{
  assert(tableaus);
  for (auto tableau_it : *tableaus) {
    Card* card = tableau_it->CardAt(line);
    if(card) {
      std::cout.width(6);
      std::cout << std::right << card->ToShortString();
    }
    else {
      std::cout.width(6);
      std::cout << std::right << "";
    }
  }
}

void InterfaceDrawVisitor::Draw(std::vector<Tableau*>* tableaus,
                                const uint8_t& num_lines) const
{
  assert(tableaus);
  DrawTableausIds(tableaus);
  for (uint8_t line_counter = 0; line_counter < num_lines; line_counter++) {
    DrawTableausInLine(tableaus, line_counter);
    std::cout << std::endl;
  }
}

