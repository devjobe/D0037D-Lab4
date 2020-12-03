#pragma once

class Card {
public:
  unsigned char suit;
  unsigned char rank;

  Card(const char *suit, const char *rank);

  void print() const;

  bool operator==(Card const &other) const;
};

