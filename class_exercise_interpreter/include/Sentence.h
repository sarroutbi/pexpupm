#ifndef SENTENCE_H
#define SENTENCE_H

#include "Data.h"

class Sentence {
public:
  Sentence()  {};
  ~Sentence() {};
  virtual void exec(Data* data) = 0;
};

#endif // SENTENCE_H
