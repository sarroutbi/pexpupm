#ifndef OPTION_MOVE_TEXT_H
#define OPTION_MOVE_TEXT_H

#include <string>
#include "OptionMove.h"
#include "OptionText.h"
#include "MovementBuilder.h"

class OptionMoveText : public OptionMove, OptionText
{
public:
  OptionMoveText(const std::string& text,
                 const uint8_t& pos);
  ~OptionMoveText();
  virtual void Display();
  virtual GameAction* GetGameAction();
  GameAction* PromptMovement();
protected:
private:
  void ShowMovements();
  char PromptMovementOption();
  MovementBuilder m_movement_builder;
  
};

#endif // OPTION_MOVE_H
