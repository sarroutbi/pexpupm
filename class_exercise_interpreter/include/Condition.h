#ifndef CONDITION_H
#define CONDITION_H

class Condition {
public:
  Condition();
  ~Condition();
  virtual void evaluate() = 0;
};

#endif // SENTENCE_H
