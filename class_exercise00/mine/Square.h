class Square : public Shape {
 public:
  Square();
  ~Square();
  virtual calculatePerimeter();
 private: 
  int m_side;
}
