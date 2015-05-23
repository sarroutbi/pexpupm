#include <vector>
#include <iostream>
#include "Algorithm.h"

void dump_data(std::vector<int>* data)
{
  std::vector<int>::iterator it;
  int elem = 0;
  for(it = data->begin(); it != data->end(); it++) {
    std::cout << "Elem:[" << elem << "]:" << *it << std::endl;
    elem++;
  }

}

int main(int argc, char* argv[])
{
  Algorithm a;
  std::vector<int> array_int;
  array_int.push_back(1);
  array_int.push_back(2);
  array_int.push_back(3);
  Data* data = new Data(array_int);
  a.edit();
  a.exec(data);
  dump_data(data->getData());
  delete data;
}
