#ifndef OPTION_SECURE_TEXT
#define OPTION_SECURE_TEXT

class OptionSecureText
{
public:
  OptionSecureText();
  virtual ~OptionSecureText();
 protected:
  bool IsUserSecure() const;
};

#endif // OPTION_SECURE_TEXT
