#ifndef DATA_H
#define DATA_H

#include <vector>

class Data {
public:
  Data();
  Data(std::vector<int> data) { m_array = data; }
  ~Data() {};
  std::vector<int>* getData() { return &m_array; }
private:
  std::vector<int> m_array;
};

#endif // DATA_H
