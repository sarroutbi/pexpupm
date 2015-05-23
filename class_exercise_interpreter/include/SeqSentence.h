#ifndef SEQ_SENTENCE_H
#define SEQ_SENTENCE_H

#include <vector>
#include "Data.h"
#include "BasicSentence.h"

class SeqSentence : public Sentence {
public:
  SeqSentence();
  ~SeqSentence();
  virtual void exec(Data* data);
  void addSentence(BasicSentence* sentence) { m_sentences.push_back(sentence); }
private:
  std::vector<BasicSentence*> m_sentences;
};

#endif // SENTENCE_H
