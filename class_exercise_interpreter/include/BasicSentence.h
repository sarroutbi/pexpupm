#ifndef BASIC_SENTENCE_H
#define BASIC_SENTENCE_H

#include "Sentence.h"

class BasicSentence : public Sentence {
public:
  BasicSentence()  {};
  ~BasicSentence() {};
  virtual void exec(Data* data) = 0;
};

#endif // BASIC_SENTENCE_H
