#include "LineVisitor.h"

int menu()
{
  std::cout << "1 - Add product" << std::endl;
  std::cout << "2 - Return product" << std::endl;
  std::cout << "3 - Abort product" << std::endl;
  std::cout << "4 - Repeat product" << std::endl;
}

int main(void)
{
  while (true) {
    process();
  }
}
