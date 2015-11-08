#ifndef INTERFACE_DRAW_VISITOR
#define INTERFACE_DRAW_VISITOR

class TextInterface;

class InterfaceDrawVisitor
{
public:
  virtual void visitTextInterface(TextInterface* text_interface) const {};
protected:
  InterfaceDrawVisitor() {};
  virtual ~InterfaceDrawVisitor() {};
};

#endif //INTERFACE_DRAW_VISITOR
