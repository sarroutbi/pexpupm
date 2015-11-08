#include "LanguageMap.h"
#include "SpanishLanguageHandler.h"
#include "EnglishLanguageHandler.h"

static LanguageMap* g_lang_map = NULL;

LanguageMap* LanguageMap::getInstance()
{
  if(!g_lang_map) {
    g_lang_map = new LanguageMap();
  }
  return g_lang_map;
}

LanguageMap::LanguageMap () : m_active_language(ENGLISH)
{
  LanguageHandler* english = new EnglishLanguageHandler;
  LanguageHandler* spanish = new SpanishLanguageHandler;
  m_language_map[ENGLISH]  = english;
  m_language_map[SPANISH]  = spanish;
}

LanguageHandler* LanguageMap::getLanguageHandler()
{
  return m_language_map[m_active_language];
}

LanguageMap::~LanguageMap()
{
  delete m_language_map[ENGLISH];
  delete m_language_map[SPANISH];
}
