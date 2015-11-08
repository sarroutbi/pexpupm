#include <assert.h>
#include "Tableau.h"
#include "TableauToTableau.h"
#include "LanguageMap.h"

const uint8_t UNDEFINED = 255;

TableauToTableau::TableauToTableau() :
  m_origin_tableau(UNDEFINED), m_destination_tableau(UNDEFINED),
  m_card_amount(UNDEFINED), m_complete(false), Movement(6)
{
  ;
}

TableauToTableau::~TableauToTableau()
{
  ;
}

std::string TableauToTableau::ToString () const
{
  return "T->T";
}

void TableauToTableau::SetOption(const uint8_t& option)
{
  if(m_origin_tableau == UNDEFINED) {
    SetOriginTableau(option);
  }
  else if(m_destination_tableau == UNDEFINED) {
    SetDestinationTableau(option);
  }
  else if(m_card_amount == UNDEFINED) {
    SetCardAmount(option);
    m_complete = true;
  }
}

std::string TableauToTableau::GetSuboption() const
{
  std::string suboption;
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();
  if(m_origin_tableau == UNDEFINED) {
    suboption = lang_handler->getWord(INSERT)
      + " " + lang_handler->getWord(ORIGIN_TABLEAU);
  }
  else if(m_destination_tableau == UNDEFINED) {
    suboption = lang_handler->getWord(INSERT)
      + " " + lang_handler->getWord(DESTINATION_TABLEAU);
  }
  else if(m_card_amount == UNDEFINED) {
    suboption = lang_handler->getWord(INSERT)
      + " " + lang_handler->getWord(CARD_AMOUNT);
  }
  return suboption;
}

void TableauToTableau::ResetMovement()
{
  m_origin_tableau = UNDEFINED;
  m_destination_tableau = UNDEFINED;
  m_card_amount = UNDEFINED;
  m_complete = false;
}

bool TableauToTableau::PerformMovement(BoardLayout* layout)
{
  assert(layout);
  bool movement_performed;
  PileSet* pile_set = layout->GetPileSet();
  assert(pile_set);
  Tableau* orig_tableau;
  Tableau* dst_tableau;
  Card* card = NULL;
  uint8_t card_counter = 0;

  if(!(orig_tableau = pile_set->GetTableau(m_origin_tableau))
     ||(orig_tableau->Size() == 0)) {
    movement_performed = false;
  }
  else if(!(dst_tableau = pile_set->GetTableau(m_destination_tableau))) {
    movement_performed = false;
  }
  else if(!m_card_amount || (m_card_amount > orig_tableau->Size())) {
    movement_performed = false;
  }
  else {
    std::vector<Card*> card_pile;
    Card* eval_card;
    eval_card = orig_tableau->CardAt(orig_tableau->Size() - m_card_amount);
    if(!eval_card || eval_card->IsTurnedDown()
       || !dst_tableau->Push(eval_card)) {
      movement_performed = false;
    }
    else {
      dst_tableau->Pop();
      while(card_counter < (m_card_amount)) {
        card = orig_tableau->Pop();
        card_pile.push_back(card);
        card_counter++;
      }
      std::vector<Card*>::reverse_iterator card_it = card_pile.rbegin();
      for (; card_it != card_pile.rend(); ++card_it) {
        dst_tableau->Push((*card_it));
      }
      movement_performed = true;
    }
  }
  ResetMovement();
  return movement_performed;
}


