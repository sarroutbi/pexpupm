#include "Frame.h"

Frame::Frame() : m_length(0) {
  ;
}

Frame::exec() 
{
  Menu menu;
  read(menu);
  paint();
}

Frame::read(Menu menu) {
  menu.exec();
  Figure shape* = menu.getFillFigured();
  if(shape) {
    m_shapes[m_length++] = shape;
  }
}

Frame::paint() {
  for (int i = 0; i < len; i++) {
    cout << i << ":" << figure[i]->getPerimeter() << endl;o
  }
}
