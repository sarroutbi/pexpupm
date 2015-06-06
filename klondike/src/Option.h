#ifndef OPTION_H
#define OPTION_H

#include <string>
#include "GameAction.h"

class Option
{
public:
  virtual void display() = 0;
  virtual GameAction getGameAction() = 0;
protected:
private:
  std::string m_text;
};

#endif OPTION_H
