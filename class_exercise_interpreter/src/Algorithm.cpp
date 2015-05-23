#include "BasicSentence.h"
#include "SumSentence.h"
#include "MultSentence.h"
#include "SeqSentence.h"
#include "Algorithm.h"
#include "ForSentence.h"

void Algorithm::edit()
{
  BasicSentence* sum = new SumSentence();
  BasicSentence* mult = new MultSentence();
  SeqSentence* seq = new SeqSentence();
  seq->addSentence(sum);
  seq->addSentence(mult);
  ForSentence* forsent = new ForSentence();
  forsent->setIterations(10);
  forsent->addBody(seq);
  m_sentence = forsent;
}

void Algorithm::exec(Data* data)
{
  m_sentence->exec(data);
}
