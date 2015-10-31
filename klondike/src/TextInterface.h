#ifndef TEXT_INTERFACE_H
#define TEXT_INTERFACE_H

#include "Option.h"
#include "BoardLayout.h"
#include "GameAction.h"
#include "Interface.h"

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
protected:
private:
};

#endif // TEXT_INTERFACE_H
