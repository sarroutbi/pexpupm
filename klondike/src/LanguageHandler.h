#ifndef LANGUAGE_HANDLER_H
#define LANGUAGE_HANDLER_H

#include <map>
#include <string>

typedef enum 
{
  MOVE  = 0,
  RESET = 1,
  EXIT  = 2,
  CARD  = 3,
  BOARD = 4,
  PILE  = 5,
  SURE  = 6,
  INTRODUCE = 7,
  INSERT = 8,
  OPTION = 9,
  YES_NO = 10,
  AVAILABLE = 11,
  OPTIONS = 12,
} word_e;

class LanguageHandler
{
public:
  LanguageHandler();
  ~LanguageHandler();
  const std::string getWord(word_e word) { return m_dict[word]; };
protected:
  std::map<word_e, std::string> m_dict;
  virtual void initDict() = 0;
private:
};

#endif // LANGUAGE_HANDLER
