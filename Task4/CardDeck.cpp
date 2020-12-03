#include "CardDeck.h"

#include <iostream>

CardDeck::CardDeck()
    : cards{{"clubs", "2"},       {"clubs", "3"},        {"clubs", "4"},
            {"clubs", "5"},       {"clubs", "6"},        {"clubs", "7"},
            {"clubs", "8"},       {"clubs", "9"},        {"clubs", "10"},
            {"clubs", "Jack"},    {"clubs", "Queen"},    {"clubs", "King"},
            {"clubs", "Ace"},

            {"diamonds", "2"},    {"diamonds", "3"},     {"diamonds", "4"},
            {"diamonds", "5"},    {"diamonds", "6"},     {"diamonds", "7"},
            {"diamonds", "8"},    {"diamonds", "9"},     {"diamonds", "10"},
            {"diamonds", "Jack"}, {"diamonds", "Queen"}, {"diamonds", "King"},
            {"diamonds", "Ace"},

            {"hearts", "2"},      {"hearts", "3"},       {"hearts", "4"},
            {"hearts", "5"},      {"hearts", "6"},       {"hearts", "7"},
            {"hearts", "8"},      {"hearts", "9"},       {"hearts", "10"},
            {"hearts", "Jack"},   {"hearts", "Queen"},   {"hearts", "King"},
            {"hearts", "Ace"},

            {"spades", "2"},      {"spades", "3"},       {"spades", "4"},
            {"spades", "5"},      {"spades", "6"},       {"spades", "7"},
            {"spades", "8"},      {"spades", "9"},       {"spades", "10"},
            {"spades", "Jack"},   {"spades", "Queen"},   {"spades", "King"},
            {"spades", "Ace"},

            {"", "Joker"},        {"", "Joker"},         {"", "Joker"}} {}

void CardDeck::print() const {
  for (int i = 0; i < 55; i++) {
    this->cards[i].print();
  }
}

Card const &CardDeck::operator[](size_t card) const {
  if (card >= NUM_CARDS_WITH_JOKERS) {
    std::cout << "CardDeck: Index of out range." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return this->cards[card];
}

Card &CardDeck::operator[](size_t card) {
  if (card >= NUM_CARDS_WITH_JOKERS) {
    std::cout << "CardDeck: Index of out range." << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return this->cards[card];
}

