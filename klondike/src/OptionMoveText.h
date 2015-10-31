#ifndef OPTION_MOVE_TEXT_H
#define OPTION_MOVE_TEXT_H

#include <string>
#include "OptionMove.h"
#include "OptionText.h"

class OptionMoveText : public OptionMove, OptionText
{
public:
  OptionMoveText(const std::string& text,
                 const uint8_t& pos);
  ~OptionMoveText();
  virtual void display();
  virtual GameAction* getGameAction();
protected:
private:
};

#endif // OPTION_MOVE_H
