#pragma once

#include "Card.h"

class CardDeck {
public:
  CardDeck();

  void print() const;

private:
  Card cards[55];
};

