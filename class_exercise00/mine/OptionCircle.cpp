OptionCircle::OptionCircle(int position) : Option(position)
{
  ;
}
 
OptionCircle::printOption()
{
  cout << option <<  " - Circle";
}

Figure* OptionCircle::getFilledFigure()
{
  int radius = getUserRadius();
  Point center_x = getUserCenter();
  Figure* circle = new Circle(radius, center);
  return circle;
}
