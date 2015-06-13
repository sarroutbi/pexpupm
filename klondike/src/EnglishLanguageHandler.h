#ifndef ENGLISH_LANGUAGE_HANDLER_H
#define ENGLISH_LANGUAGE_HANDLER_H

#include "LanguageHandler.h"

class EnglishLanguageHandler : public LanguageHandler
{
public:
  EnglishLanguageHandler();
  ~EnglishLanguageHandler();
protected:
  virtual void initDict();
};

#endif // ENGLISH_LANGUAGE_HANDLER
