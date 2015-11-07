#ifndef TABLEAU_TO_FOUNDATION_H
#define TABLEAU_TO_FOUNDATION_H

#include "Movement.h"
#include "BoardLayout.h"

class TableauToFoundation : public Movement
{
public:
  TableauToFoundation();
  ~TableauToFoundation();
  void SetOriginTableau(const uint8_t& orig_tableau)
  { m_origin_tableau = orig_tableau; m_complete = true; };
  virtual bool PerformMovement(BoardLayout* layout);
  virtual std::string ToString () const;
  virtual bool Complete() { return m_complete; };
  virtual void SetOption(const uint8_t& option);
  virtual std::string GetSuboption() const;
private:
  uint8_t m_origin_tableau;
  bool m_complete;
};

#endif // WASTE_TO_TABLEAU
