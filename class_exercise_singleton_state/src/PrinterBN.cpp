#include <iostream>
#include "PrinterBN.h"

PrinterBN::PrinterBN()
{

}

PrinterBN::~PrinterBN()
{

}

void PrinterBN::print(const std::string& text)
{
  std::cout << "Printing " << text << " in BN" << std::endl;
}
