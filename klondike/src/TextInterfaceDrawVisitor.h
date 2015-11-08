#ifndef TEXT_INTERFACE_DRAW_VISITOR
#define TEXT_INTERFACE_DRAW_VISITOR

#include "InterfaceDrawVisitor.h"
#include "BoardLayout.h"

class TextInterface;

class TextInterfaceDrawVisitor : public InterfaceDrawVisitor
{
public:
  TextInterfaceDrawVisitor();
  ~TextInterfaceDrawVisitor();
  virtual void visitTextInterface(TextInterface* text_interface) const;
private:
  void Draw(Deck* deck) const;
  void Draw(Waste* deck) const;
  void Draw(std::vector<Foundation*>* foundation) const;
  void Draw(std::vector<Tableau*>* tableau,
            const uint8_t& num_lines) const;
  void DrawTableausIds(std::vector<Tableau*>* tableau) const;
  void DrawTableausInLine(std::vector<Tableau*>* tableau,
                          const uint8_t& num_lines) const;
  void DrawDeckWasteFoundationHeader(std::vector<Foundation*>* foundation) const;
};

#endif //TEXT_INTERFACE_DRAW_VISITOR
