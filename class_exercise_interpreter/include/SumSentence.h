#ifndef SUM_SENTENCE_H
#define SUM_SENTENCE_H

#include "BasicSentence.h"

class SumSentence : public BasicSentence {
public:
  SumSentence()  {};
  ~SumSentence() {};
  virtual void exec(Data* data);
};

#endif // SUM_SENTENCE_H
