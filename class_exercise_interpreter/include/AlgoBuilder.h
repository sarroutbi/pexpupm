#ifndef ALGO_BUILDER_H
#define ALGO_BUILDER_H

#include <stdint.h>
#include <stack>
#include "Sentence.h"

class AlgoBuilder {
public:
  AlgoBuilder(Data* data);
  ~AlgoBuilder();
  void OpenFor(const uint8_t& iterations);
  void CloseFor();
  void Sum();
  void Mult();
private:
  std::stack<SeqSentence*> m_sentence_stack;
  Data* m_data;
};

#endif // ALGO_BUILDER_H
