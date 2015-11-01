#ifndef MOVEMENT_H
#define MOVEMENT_H

#include <string>
#include <stdint.h>
#include "Pile.h"

class BoardLayout;

class Movement
{
public:
  Movement () : m_source(NULL), m_destination(NULL), m_id(0) {};
  explicit  Movement (uint8_t id) : m_source(NULL), m_destination(NULL), m_id(id) {};
  virtual ~Movement () {};
  void SetDestination (Pile* dst) { m_destination = dst; }
  Pile* GetDestination () { return m_destination; }
  void SetSource (Pile* source) { m_source = source;  }
  Pile* GetSource () { return m_source; }
  uint8_t GetId() { return m_id;}
  virtual std::string ToString() const = 0;
  virtual bool PerformMovement(BoardLayout* layout) = 0;
private:
  uint8_t m_id;
  Pile* m_source;
  Pile* m_destination;
};

#endif // MOVEMENT_H
