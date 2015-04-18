class Option {
 public:
  Option(int position);
  virtual showMenuText() = 0;
  virtual Shape* getFilledFigure() = 0;
 private:
  uint32_t m_position = 0;
};
