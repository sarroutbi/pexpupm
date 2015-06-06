#ifndef LANGUAGE_HANDLER_H
#define LANGUAGE_HANDLER_H

#include <map>

class LanguageHandler
{
public:
  LanguageHandler::LanguageHandler();
  LanguageHandler::~LanguageHanadler();
  virtual void initDict() = 0;
private:
  std::map<std::string, std::string> m_lang_map;
};

#endif // LANGUAGE_HANDLER
