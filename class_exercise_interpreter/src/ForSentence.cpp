#include <assert.h>
#include <iostream>
#include "ForSentence.h"

void ForSentence::exec(Data* data)
{
  for(int num = 0; num < m_times; num++) {
    m_seq->exec(data);
  }
}
