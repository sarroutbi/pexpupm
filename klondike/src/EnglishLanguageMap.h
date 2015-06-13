#ifndef ENGLISH_LANGUAGE_MAP_H
#define ENGLISH_LANGUAGE_MAP_H

#include "LanguageHandler.h"

class EnglishLanguageMap : public LanguageMap
{
public:
  static LanguageMap* getInstance();
  void setActiveLanguage(const uint32_t& alang) { m_active_language(alang); };
protected:
private:
  LanguageMap();
  std::map<std::string, LanguageHandler*> m_lang_map;
  uint32_t m_active_language;
};

#endif // LANGUAGE_MAP
