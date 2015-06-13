#ifndef TEXT_INTERFACE_H
#define TEXT_INTERFACE_H

#include "Option.h"
#include "BoardLayout.h"
#include "GameAction.h"
#include "Interface.h"

class TextInterface : public Interface
{
public:
  virtual void createOptions();
  virtual void displayOptions();
  virtual void draw(const BoardLayout& layout);
  virtual GameAction* getPlayerAction();
protected:
private:
};

#endif // TEXT_INTERFACE_H
