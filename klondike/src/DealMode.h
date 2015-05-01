#ifndef DEALMODE_H
#define DEALMODE_H

#include <string>
#include <vector>

enum e_deal_type {
  CARD1_1DEAL = 0,
  CARD1_3DEALS = 1,
  CARD1_INFDEALS = 2,
  CARD3_1DEAL = 3,
  CARD3_3DEALS = 4,
  CARD3_INFDEALS = 5
};

/**
  * class DealMode
  * 
  */

class DealMode
{
public:

  // Constructors/Destructors
  //  


  /**
   * Empty Constructor
   */
  DealMode ();

  /**
   * Empty Destructor
   */
  ~DealMode ();

  /**
   * @return bool
   * @param  type
   */
  bool SetDealType (e_deal_type type);


  /**
   * @return e_deal_type
   */
  e_deal_type GetDealType ();

};

#endif // DEALMODE_H
