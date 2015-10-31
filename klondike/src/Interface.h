#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdint.h>
#include <map>
#include "Option.h"
#include "BoardLayout.h"
#include "GameAction.h"

class Interface
{
public:
  Interface();
  virtual ~Interface();
  void DisplayOptions();
  virtual void Draw(const BoardLayout& layout) = 0;
  virtual GameAction* GetPlayerAction() = 0;
protected:
  std::map<uint8_t, Option*> m_option_list;
private:
};

#endif // INTERFACE_H
