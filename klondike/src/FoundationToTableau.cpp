#include <assert.h>
#include "Tableau.h"
#include "FoundationToTableau.h"
#include "LanguageMap.h"

const uint8_t UNDEFINED = 255;

FoundationToTableau::FoundationToTableau() :
  m_origin_foundation(UNDEFINED), m_destination_tableau(UNDEFINED),
  m_complete(false), Movement(5)
{
  ;
}

FoundationToTableau::~FoundationToTableau()
{
  ;
}

std::string FoundationToTableau::ToString () const
{
  return "F->T";
}

void FoundationToTableau::SetOption(const uint8_t& option)
{
  if(m_origin_foundation == UNDEFINED) {
    SetOriginFoundation(option);
  }
  else if(m_destination_tableau == UNDEFINED) {
    SetDestinationTableau(option);
    m_complete = true;
  }
}

std::string FoundationToTableau::GetSuboption() const
{
  std::string suboption;
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();
  if(m_origin_foundation == UNDEFINED) {
    suboption = lang_handler->getWord(INSERT)
      + " " + lang_handler->getWord(ORIGIN_FOUNDATION);
  }
  else if(m_destination_tableau == UNDEFINED) {
    suboption = lang_handler->getWord(INSERT)
      + " " + lang_handler->getWord(DESTINATION_TABLEAU);
  }
  return suboption;
}

bool FoundationToTableau::PerformMovement(BoardLayout* layout)
{
  assert(layout);
  bool movement_performed;
  PileSet* pile_set = layout->GetPileSet();
  assert(pile_set);
  Foundation* foundation = pile_set->GetFoundation(m_origin_foundation);
  Card* card = NULL;

  if(!foundation || (foundation->Size() == 0)) {
    movement_performed = false;
  }
  else {
    card = foundation->Pop();
    Tableau* tableau = (*(pile_set->GetTableaus()))[m_destination_tableau];
    if(!card || !tableau || !tableau->Push(card)) {
      foundation->Push(card);
      movement_performed = false;
    }
    else {
      movement_performed = true;
    }
  }
  m_origin_foundation = UNDEFINED;
  m_destination_tableau = UNDEFINED;
  m_complete = false;
  return movement_performed;
}


