#pragma once

class Card {
  unsigned char suit;
  unsigned char rank;

public:
  Card(const char *suit, const char *rank);

  void print() const;
};

