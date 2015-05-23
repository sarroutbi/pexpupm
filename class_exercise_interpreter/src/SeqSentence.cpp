#include "SeqSentence.h"

SeqSentence::SeqSentence() : m_sentences()
{
  ;
}

SeqSentence::~SeqSentence()
{
  ;
}

void SeqSentence::exec(Data* data)
{
  std::vector<BasicSentence*>::const_iterator itsent;
  for (itsent = m_sentences.begin(); itsent != m_sentences.end();
       itsent++)
  {
    (*itsent)->exec(data);
  }
}
