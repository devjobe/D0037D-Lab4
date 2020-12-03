#pragma once

#include "Card.h"

class CardDeck {
public:

  CardDeck();

  void print() const;

  Card const &operator[](size_t card) const;
  Card &operator[](size_t card);

  enum { 
    NUM_CARDS = 52,
    NUM_CARDS_WITH_JOKERS = 55,
  };

  
private:
  Card cards[NUM_CARDS_WITH_JOKERS];
};

