#ifndef SPANISH_LANGUAGE_HANDLER_H
#define SPANISH_LANGUAGE_HANDLER_H

#include "LanguageHandler.h"

class SpanishLanguageHandler : public LanguageHandler
{
public:
  SpanishLanguageHandler();
  ~SpanishLanguageHandler();
protected:
  virtual void initDict();
};

#endif // SPANISH_LANGUAGE_HANDLER
