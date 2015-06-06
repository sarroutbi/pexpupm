#ifndef LANGUAGE_MAP_H
#define LANGUAGE_MAP_H

#include "LanguageHandler.h"
#include <string>
#include <map>

class LanguageMap
{
public:
  static LanguageMap* getInstance();
protected:
private:
  LanguageMap::LanguageMap();
  registerLanguage(std::string, LanguageHandler* handler);
  std::map<std::string, LanguageHandler*> m_lang_map;
};

#endif LANGUAGE_MAP
