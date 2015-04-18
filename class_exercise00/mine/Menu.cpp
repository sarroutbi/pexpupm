Menu::Menu()
{
  m_options.push_back(new OptionCircle(1));
  m_options.push_back(new OptionSquare(2));
  m_options.push_back(new OptionExit(3));
}

Shape* Menu::getFilledFigure()
{
  for (int i = 0; i < m_options.size; i++) {
    m_options.printOption();
  }
  int option;
  cout << "Option?:";
  cin >> option;
  return option[i-1]->getFigure();
}


