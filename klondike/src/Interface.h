#ifndef INTERFACE_H
#define INTERFACE_H

#include "Option.h"
#include "BoardLayout.h"
#include "GameAction.h"

class Interface
{
public:
  virtual void createOptions() = 0;
  virtual void displayOptions() = 0;
  virtual void draw(const BoardLayout& layout) = 0;
  virtual GameAction& getPlayerAction() = 0;
protected:
private:
  std::vector<Option> m_option_list;
};

#endif INTERFACE_H
