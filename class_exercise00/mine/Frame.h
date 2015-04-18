class Frame {
 public:
  Frame();
  void paint();
  void exec();
 private:
  int m_length;
  void read(Menu);
  Figure* m_shapes[100];
};
