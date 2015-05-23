#ifndef MULT_SENTENCE_H
#define MULT_SENTENCE_H

#include "BasicSentence.h"

class MultSentence : public BasicSentence {
public:
  MultSentence()  {};
  ~MultSentence() {};
  virtual void exec(Data* data);
};

#endif // MULT_SENTENCE_H
