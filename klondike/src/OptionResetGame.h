#ifndef OPTION_RESET_GAME_H
#define OPTION_RESET_GAME_H

class OptionResetGame : public Option
{
public:
  OptionResetGame();
  ~OptionResetGame();
  virtual void display() = 0;
  virtual GameAction getGameAction() = 0;
protected:
};

#endif OPTION_RESET_GAME_H
