#include <assert.h>
#include "Tableau.h"
#include "TableauToFoundation.h"
#include "LanguageMap.h"

#include <iostream>

TableauToFoundation::TableauToFoundation() :
  m_origin_tableau(0), m_complete(false), Movement(4)
{
  ;
}

TableauToFoundation::~TableauToFoundation()
{
  ;
}

std::string TableauToFoundation::ToString () const
{
  return "T->F";
}

void TableauToFoundation::SetOption(const uint8_t& option)
{
  SetOriginTableau(option);
}

std::string TableauToFoundation::GetSuboption() const
{
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();
  std::string suboption = lang_handler->getWord(INSERT)
            + " " + lang_handler->getWord(ORIGIN_TABLEAU);
  return suboption;
}

bool TableauToFoundation::PerformMovement(BoardLayout* layout)
{
  assert(layout);
  bool movement_performed;
  PileSet* pile_set = layout->GetPileSet();
  assert(pile_set);
  Card* card = NULL;
  Tableau* tableau = (*(pile_set->GetTableaus()))[m_origin_tableau];

  if(!tableau || (tableau->Size() == 0)) {
    movement_performed = false;
  }
  else {
    card = tableau->BottomCard();
    Foundation* foundation = pile_set->GetFoundation(card->GetSuit());
    if(!card || !foundation || !foundation->Push(card)) {
      // QUIT
      if(!card) {
        std::cout << "NO CARD IN TABLEAU:" << card->ToShortString();
      }
      else {
        std::cout << "CARD:" << card->ToShortString();
      }
      //

      movement_performed = false;
    }
    else {
      tableau->Pop();
      movement_performed = true;
    }

  }
  m_complete = false;
  return movement_performed;
}


