#include "Card.h"

#include <iostream>

static const int NUM_SUITS = 5;
static const char* SUITS[NUM_SUITS] = { "", "clubs", "diamonds", "hearts", "spades" };

static const int NUM_RANKS = 14;
static const char* RANKS[NUM_RANKS] = { "Joker", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

static int find_suit(const char *suit) {
  for (int i = 0; i < NUM_SUITS; i++) {
    if (_strcmpi(SUITS[i], suit) == 0) {
      return i;
    }
  }
  return -1;
}

static int find_rank(const char *rank) {
  for (int i = 0; i < NUM_RANKS; i++) {
    if (_strcmpi(RANKS[i], rank) == 0) {
      return i;
    }
  }
  return -1;
}

Card::Card(const char *suit, const char *rank) {
  int s = find_suit(suit);
  if (s < 0) {
    std::cout << "Invalid suit: " << suit << std::endl;
    std::exit(EXIT_FAILURE);
  }

  int r = find_rank(rank);
  if (r < 0) {
    std::cout << "Invalid rank: " << rank << std::endl;
    std::exit(EXIT_FAILURE);
  }

  this->suit = s;
  this->rank = r;
}


void Card::print() const {
  const char *suit = SUITS[this->suit];
  const char *rank = RANKS[this->rank];

  if (strcmp(suit, "") == 0)
    std::cout << rank << std::endl;
  else
    std::cout << rank << " of " << suit << std::endl;
}