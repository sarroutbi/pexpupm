class OptionCircle : Option
{
 public:
  OptionCircle(int position);
  virtual printOption(); 
 private:
  virtual Figure* getFilledFigure();
};
