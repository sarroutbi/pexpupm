#ifndef BOARDLAYOUT_H
#define BOARDLAYOUT_H

#include <string>
#include <vector>

#include "Movement.h"
#include "Pile.h"
#include "Foundation.h"

const unsigned int DEFAULT_TABLEAU_AMOUNT = 7;
/**
  * class BoardLayout
  * 
  */
class BoardLayout
{
public:
  /**
   * Empty Constructor
   */
  BoardLayout (const unsigned int num_tableaus = DEFAULT_TABLEAU_AMOUNT);

  /**
   * Empty Destructor
   */
  virtual ~BoardLayout ();

  /**
   */
  void ResetPiles ();


  /**
   * @return bool
   */
  bool GameFinished ();

protected:

private:
  std::vector<Foundation> m_foundations;
  std::vector<Pile> m_tableaus;
  Pile m_deck;
  Pile m_waste;
};

#endif // BOARDLAYOUT_H
