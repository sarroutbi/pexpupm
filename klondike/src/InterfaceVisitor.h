#ifndef INTERFACE_VISITOR
#define INTERFACE_VISITOR

class TextInterface;

class InterfaceVisitor
{
public:
  virtual void visitTextInterface(TextInterface* text_interface) const {};
protected:
  InterfaceVisitor() {};
  virtual ~InterfaceVisitor() {};
};

#endif //INTERFACE_VISITOR
