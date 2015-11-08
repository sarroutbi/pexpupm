#ifndef TABLEAU_TO_TABLEAU_H
#define TABLEAU_TO_TABLEAU_H

#include "Movement.h"
#include "BoardLayout.h"

class TableauToTableau : public Movement
{
public:
  TableauToTableau();
  ~TableauToTableau();
  void SetOriginTableau(const uint8_t& orig_tableau)
  { m_origin_tableau = orig_tableau; }
  void SetDestinationTableau(const uint8_t& dst_tableau)
  { m_destination_tableau = dst_tableau; };
  void SetCardAmount(const uint8_t& card_amount)
  { m_card_amount = card_amount; };
  virtual bool PerformMovement(BoardLayout* layout);
  virtual std::string ToString () const;
  virtual bool Complete() { return m_complete; };
  virtual void SetOption(const uint8_t& option);
  virtual std::string GetSuboption() const;
private:
  void ResetMovement();
  uint8_t m_origin_tableau;
  uint8_t m_destination_tableau;
  uint8_t m_card_amount;
  bool m_complete;
};

#endif // TABLEAU_TO_TABLEAU
