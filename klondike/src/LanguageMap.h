#ifndef LANGUAGE_MAP_H
#define LANGUAGE_MAP_H

#include <stdint.h>
#include <string>
#include <map>
#include "LanguageHandler.h"

typedef enum {
  ENGLISH = 0,
  SPANISH = 1
} lang_e;

class LanguageMap
{
public:
  static LanguageMap* getInstance();
  void setActiveLanguage(const lang_e& alang) { m_active_language = alang; };
  LanguageHandler* getLanguageHandler();
protected:
private:
  LanguageMap();
  ~LanguageMap();
  std::map<lang_e, LanguageHandler*> m_language_map;
  lang_e m_active_language;
};

#endif // LANGUAGE_MAP
