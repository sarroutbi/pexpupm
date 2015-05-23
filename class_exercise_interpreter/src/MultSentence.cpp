#include <assert.h>
#include <iostream>
#include "MultSentence.h"

void MultSentence::exec(Data* data)
{
  assert(data);
  std::vector<int>* pData = data->getData();
  assert(pData);
  int result = 0;
  std::vector<int>::iterator iit;
  for(iit = pData->begin(); iit != pData->end(); iit++) {
    (*iit) *= 2;
  }
}
