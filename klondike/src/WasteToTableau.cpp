#include <assert.h>
#include "Tableau.h"
#include "WasteToTableau.h"
#include "LanguageMap.h"

WasteToTableau::WasteToTableau() :
  m_destination_tableau(0), m_complete(false), Movement(3)
{
  ;
}

WasteToTableau::~WasteToTableau()
{
  ;
}

std::string WasteToTableau::ToString () const
{
  return "W->T";
}

void WasteToTableau::SetOption(const uint8_t& option)
{
  SetDestinationTableau(option);
}

std::string WasteToTableau::GetSuboption() const
{
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();
  std::string suboption = lang_handler->getWord(INSERT)
            + " " + lang_handler->getWord(DESTINATION_TABLEAU);
  return suboption;
}

bool WasteToTableau::PerformMovement(BoardLayout* layout)
{
  assert(layout);
  bool movement_performed;
  PileSet* pile_set = layout->GetPileSet();
  assert(pile_set);
  Waste* waste = pile_set->GetWaste();
  assert(waste);
  Card* card = NULL;

  if((waste->Size() == 0)) {
    movement_performed = false;
  }
  else {
    card = waste->Pop();
    Tableau* tableau = (*(pile_set->GetTableaus()))[m_destination_tableau];
    if(!card || !tableau || !tableau->Push(card)) {
      waste->Push(card);
      movement_performed = false;
    }
    else {
      movement_performed = true;
    }
  }
  m_complete = false;
  return movement_performed;
}


