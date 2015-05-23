#include "SeqSentence.h"
#include "AlgoBuilder.h"
#include "ForSentence.h"

AlgoBuilder::AlgoBuilder(Data* data) : m_data(data)
{
  SeqSentence* seq = new SeqSentence();
  m_sentence_stack.push(seq);
}

AlgoBuilder::~AlgoBuilder()
{
  
}

void AlgoBuilder::OpenFor(const uint8_t& iterations)
{
  ForSentence* forsent = new ForSentence();
  forsent->setIterations(iterations);
  m_sentence_stack.push(forsent);
}

void AlgoBuilder::CloseFor()
{
  Sentence* sent = m_sentence_stack.top();
  sent->exec(m_data);
  m_sentence_stack.pop();
}

void AlgoBuilder::Sum()
{
  SeqSentence* top = m_sentence_stack.top();
  top->add(new SumSentence());
}

void AlgoBuilder::Mult()
{
  Sentence* top = m_sentence_stack.top();
  top->add(new MultSentence());
}
