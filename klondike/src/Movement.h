#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <string>
#include <stdint.h>
#include "Pile.h"

class BoardLayout;

class Movement
{
public:
  explicit  Movement (uint8_t id) {};
  virtual ~Movement () {};
  uint8_t GetId() { return m_id;}
  virtual std::string ToString() const = 0;
  virtual bool PerformMovement(BoardLayout* layout) = 0;
  virtual void SetOption(const uint8_t& option) { };
  virtual std::string GetSuboption() const {};
  virtual bool Complete() { return true; };
private:
  uint8_t m_id;
};

#endif // MOVEMENT_H
