#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "Data.h"
#include "Sentence.h"

class Algorithm {
public:
  Algorithm()  {};
  ~Algorithm() {};
  void edit();
  void exec(Data* data);
private:
  Sentence* m_sentence;
};

#endif // SENTENCE_H
