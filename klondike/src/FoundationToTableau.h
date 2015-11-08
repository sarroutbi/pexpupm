#ifndef FOUNDATION_TO_TABLEAU_H
#define FOUNDATION_TO_TABLEAU_H

#include "Movement.h"
#include "BoardLayout.h"

class FoundationToTableau : public Movement
{
public:
  FoundationToTableau();
  ~FoundationToTableau();
  void SetOriginFoundation(const uint8_t& orig_foundation)
  { m_origin_foundation = orig_foundation; };
  void SetDestinationTableau(const uint8_t& dst_tableau)
  { m_destination_tableau = dst_tableau; };
  virtual bool PerformMovement(BoardLayout* layout);
  virtual std::string ToString () const;
  virtual bool Complete() { return m_complete; };
  virtual void SetOption(const uint8_t& option);
  virtual std::string GetSuboption() const;
private:
  uint8_t m_origin_foundation;
  uint8_t m_destination_tableau;
  bool m_complete;
};

#endif // FOUNDATION_TO_TABLEAU
