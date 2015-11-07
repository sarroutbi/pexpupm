#ifndef WASTE_TO_TABLEAU_H
#define WASTE_TO_TABLEAU_H

#include "Movement.h"
#include "BoardLayout.h"

class WasteToTableau : public Movement
{
public:
  WasteToTableau();
  ~WasteToTableau();
  void SetDestinationTableau(const uint8_t& dst_tableau)
  { m_destination_tableau = dst_tableau; m_complete = true; };
  virtual bool PerformMovement(BoardLayout* layout);
  virtual std::string ToString () const;
  virtual bool Complete() { return m_complete; };
  virtual void SetOption(const uint8_t& option);
  virtual std::string GetSuboption() const;
private:
  uint8_t m_destination_tableau;
  bool m_complete;
};

#endif // WASTE_TO_TABLEAU
