#ifndef BOARDLAYOUT_H
#define BOARDLAYOUT_H

#include <string>
#include <vector>

#include "Movement.h"
#include "Foundation.h"
#include "PileSet.h"

const unsigned int DEFAULT_TABLEAU_AMOUNT = 7;

class BoardLayout
{
public:
  BoardLayout (const unsigned int num_tableaus = DEFAULT_TABLEAU_AMOUNT);
  virtual ~BoardLayout ();
  void ResetPiles ();
  bool GameFinished ();
protected:
private:
  PileSet m_pile_set;
};

#endif // BOARDLAYOUT_H
