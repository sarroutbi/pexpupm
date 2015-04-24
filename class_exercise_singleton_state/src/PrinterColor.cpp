#include <iostream>
#include "PrinterColor.h"

PrinterColor::PrinterColor()
{

}

PrinterColor::~PrinterColor()
{

}

void PrinterColor::print(const std::string& text)
{
  std::cout << "Printing " << text << " in Color" << std::endl;
}
