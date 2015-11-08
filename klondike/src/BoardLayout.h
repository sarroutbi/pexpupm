#ifndef BOARDLAYOUT_H
#define BOARDLAYOUT_H

#include <string>
#include <vector>

#include "Movement.h"
#include "Foundation.h"
#include "PileSet.h"
#include "BoardTypes.h"

class PileSet;

const unsigned int DEFAULT_TABLEAU_AMOUNT = 7;

class BoardLayout
{
public:
  BoardLayout (const unsigned int& num_tableaus = DEFAULT_TABLEAU_AMOUNT,
               const e_board_type& board_type = BOARD_TYPE_FRENCH);
  ~BoardLayout ();
  void ResetPiles ();
  bool GameFinished () const;
  PileSet* GetPileSet() const;
  void SetGameFinished();
protected:
private:
  PileSet* m_pile_set;
  bool m_game_finished;
};

#endif // BOARDLAYOUT_H
