#ifndef OPTION_EXIT_H
#define OPTION_EXIT_H

class OptionExit : public Option
{
public:
  OptionExit();
  ~OptionExit();
  virtual void display() = 0;
  virtual GameAction getGameAction() = 0;
protected:
};

#endif OPTION_EXIT_H
