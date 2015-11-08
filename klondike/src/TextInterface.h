#ifndef TEXT_INTERFACE_H
#define TEXT_INTERFACE_H

#include "Option.h"
#include "BoardLayout.h"
#include "GameAction.h"
#include "Interface.h"
#include "Deck.h"
#include "Waste.h"
#include "InterfaceDrawVisitor.h"

class TextInterface : public Interface
{
public:
  TextInterface();
  ~TextInterface();
  void CreateOptions();
  void DeleteOptions() const;
  void DisplayOptions();
  virtual void Draw(const BoardLayout& layout);
  int PromptOption() const;
  virtual GameAction* GetPlayerAction();
  PileSet* GetPileSet() { return m_pile_set; };
  void accept(const InterfaceDrawVisitor& draw_visitor);
protected:
private:
  PileSet* m_pile_set;
};

#endif // TEXT_INTERFACE_H
