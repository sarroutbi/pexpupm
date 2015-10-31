#ifndef OPTION_TEXT
#define OPTION_TEXT

#include <string>
#include <stdint.h>

class OptionText
{
public:
  OptionText(const std::string& text,
             const uint8_t& pos) : m_text(text), m_pos(pos) {};
  virtual ~OptionText() {};
 protected:
  std::string m_text;
  const uint8_t m_pos;
};

#endif // OPTION_TEXT
