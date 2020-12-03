#include <iostream>
#include <random>
#include <vector>

#include "../Task4/CardDeck.h"

class CardUtilities {
public:
  static void shuffle(CardDeck *input);
  static void sort(CardDeck *input);

  // Changed function signature since the given one was unusable since returning
  // only Card* doesnt allow the caller to know how many elements are in the
  // array.
  // Deck implementation doesn't support removing so I added the additional
  // num_cards argument.
  static std::vector<Card> checkMissing(CardDeck const *input,
                                        size_t num_cards);
};

using namespace std;

void CardUtilities::shuffle(CardDeck *input) {
  random_device rand_dev;
  auto index_dist =
      uniform_int_distribution<size_t>(0, CardDeck::NUM_CARDS_WITH_JOKERS - 1);
  auto gen = default_random_engine(rand_dev());

  // Swap every card slot with another random card slot (including itself).
  for (size_t first_index = 0; first_index < CardDeck::NUM_CARDS_WITH_JOKERS;
       ++first_index) {
    auto second_index =
        (first_index + index_dist(gen)) % CardDeck::NUM_CARDS_WITH_JOKERS;
    swap((*input)[first_index], (*input)[second_index]);
  }
}

int sorting_order(Card const &a, Card const &b) {
  if (a.rank == b.rank) {
    return int(a.suit) - b.suit;
  } else {
    return int(a.rank) - b.rank;
  }
}

void CardUtilities::sort(CardDeck *input) {
  // some kind of sort? (slow sort?)
  for (size_t sorted = 1; sorted < CardDeck::NUM_CARDS_WITH_JOKERS; ++sorted) {
    // bubble down
    for (size_t ndx = sorted; ndx > 0; --ndx) {
      Card &a = (*input)[ndx];
      Card &b = (*input)[ndx - 1];

      if (sorting_order(a, b) < 0) {
        swap(a, b);
      }
    }
  }
}

int count_cards(CardDeck const &deck, size_t num_cards, Card const &card) {
  int count = 0;
  for (size_t index = 0; index < num_cards; ++index) {
    count += deck[index] == card;
  }
  return count;
}

std::vector<Card> CardUtilities::checkMissing(CardDeck const *input,
                                            size_t num_cards) {    
  std::vector<Card> missing;
  CardDeck const original;

  for (size_t index = 0; index < CardDeck::NUM_CARDS_WITH_JOKERS; ++index) {
    Card const &card = original[index];
    // Makes sure a missing card is counted only once incase of duplicates (jokers).
    // Should be cheaper than keeping track of all counted in most cases.
    if (find(missing.begin(), missing.end(), card) == missing.end()) {
      int diff = count_cards(original, CardDeck::NUM_CARDS_WITH_JOKERS, card) -
                 count_cards(*input, num_cards, card);
      for (int i = 0; i < diff; i++) {
        missing.push_back(card);
      }
      // diff < 0 ? Duplicates ?
    }
  }

  return missing;
}

int main()
{
  CardDeck deck;
  std::cout << "Original deck:" << endl;
  deck.print();
  std::cout << endl;

  CardUtilities::shuffle(&deck);
  std::cout << "Shuffled deck:" << endl;
  deck.print();
  std::cout << endl;

  CardUtilities::sort(&deck);
  std::cout << "Sorted deck:" << endl;
  deck.print();
  std::cout << endl;

  int const exclude_cards = 5;
  CardUtilities::shuffle(&deck);
  cout << "Excluding " << exclude_cards << " cards from a shuffled deck. " << endl;
  cout << "Cards excluded:" << endl;
  for (size_t i = CardDeck::NUM_CARDS_WITH_JOKERS - exclude_cards;
       i < CardDeck::NUM_CARDS_WITH_JOKERS; ++i) {
    deck[i].print();
  }
  cout << endl;

  auto missing = CardUtilities::checkMissing(&deck, CardDeck::NUM_CARDS_WITH_JOKERS - exclude_cards);
  cout << "Missing cards found:" << endl;
  for (auto const &it : missing) {
    it.print();
  }
  cout << endl;

  return 0;
}