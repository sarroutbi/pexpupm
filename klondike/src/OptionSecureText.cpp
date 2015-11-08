#include <iostream>
#include "OptionSecureText.h"
#include "LanguageMap.h"

OptionSecureText::OptionSecureText()
{
  ;
}

OptionSecureText::~OptionSecureText()
{
  ;
}

bool OptionSecureText::IsUserSecure() const
{
  LanguageHandler* lang_handler = LanguageMap::getInstance()->getLanguageHandler();
  char option;
  std::cout << lang_handler->getWord(SURE) + "?" + lang_handler->getWord(YES_NO) + ":";
  std::cin >> option;
  if (lang_handler->getWord(YES_CHARS).find(option) != std::string::npos) {
    return true;
  }
  return false;
}
