#ifndef FOR_SENTENCE_H
#define FOR_SENTENCE_H

#include <stdint.h>
#include "Sentence.h"
#include "SeqSentence.h"

class ForSentence : public Sentence {
public:
  ForSentence()  {};
  ~ForSentence() {};
  void setIterations(const uint8_t times) {m_times = times;};
  void addBody(SeqSentence* seq) { m_seq = seq; }
  virtual void exec(Data* data);
private:
  uint8_t m_times;
  SeqSentence* m_seq;
};

#endif // FOR_SENTENCE_H
