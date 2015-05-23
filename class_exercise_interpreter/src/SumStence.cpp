#include <assert.h>
#include <iostream>
#include "SumSentence.h"

void SumSentence::exec(Data* data)
{
  assert(data);
  std::vector<int>* pData = data->getData();
  assert(pData);
  std::vector<int>::iterator iit;
  for(iit = pData->begin(); iit != pData->end(); iit++) {
    (*iit)++;
  }
}
