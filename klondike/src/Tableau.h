#ifndef TABLEAU_H
#define TABLEAU_H

#include "Pile.h"

#include <string>
#include <vector>


class Tableau : public Pile
{
public:
  Tableau (const uint8_t& id);
  ~Tableau ();
  virtual bool Push(Card* card);
  virtual Card* Pop ();
  virtual bool Full() const;
  void SetInGame() { m_in_game = true; };
  bool IsInGame() const { return m_in_game; };
  uint8_t GetId() const { return m_tableau_id; };
private:
  bool PushInGameCard(Card* card);
  bool PushOutGameCard(Card* card);
  uint8_t m_tableau_id;
  bool m_in_game;
};

#endif // TABLEAU_H
