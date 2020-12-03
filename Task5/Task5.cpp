#include <iostream>
#include <random>
#include <cstdlib>

#include "../Task4/CardDeck.h"
#include "../Task4/Card.h"

class CardGame {
public:
  CardGame(CardDeck deck);

  void initialize();
  void play();

  static int compare(Card const &a, Card const &b);

private:
  CardDeck deck;
  int rounds = 0;
};

using namespace std;

CardGame::CardGame(CardDeck deck) : deck(deck) {}

void CardGame::initialize() { 
  cout << "How many rounds do you want to play? ";
  int n;
  if (!(cin >> n) || n < 0) {
    cout << "Ok bye." << endl;
    std::exit(EXIT_SUCCESS);
  }
  this->rounds = n;
}

int CardGame::compare(Card const &a, Card const &b) {
  if (a.rank == b.rank) {
    return int(a.suit) - b.suit;
  } else {
    return int(a.rank) - b.rank;
  }
}

void CardGame::play() {

  random_device rand_dev;
  auto index_dist =
      uniform_int_distribution<size_t>(0, CardDeck::NUM_CARDS_WITH_JOKERS - 1);
  
  // Used to select another card besides the first random one.
  auto secondary_dist =
      uniform_int_distribution<size_t>(1, CardDeck::NUM_CARDS_WITH_JOKERS - 1);
  auto gen = default_random_engine(rand_dev());

  int points = 0;
  for (int round = 0; round < this->rounds; round++) {
    auto first_index = index_dist(gen);
    auto second_index = (first_index + secondary_dist(gen)) % CardDeck::NUM_CARDS_WITH_JOKERS;

    Card const &computer = this->deck[first_index];
    Card const &player = this->deck[second_index];

    cout << "Computer: ";
    computer.print();
    cout << "Player: ";
    player.print();

    int res = CardGame::compare(computer, player);
    cout << "Outcome: ";
    if (res == 0) {
      cout << "Tie!" << endl;
    } else if (res > 0) {
      cout << "Computer won." << endl;
      --points;
    } else {
      ++points;
      cout << "Player won." << endl;
    }
    cout << endl;
  }

  if (points > 0) {
    cout << "You beat the computer!" << endl;
  } else if(points < 0) {
    cout << "Wow sad. You lost." << endl;
  } else {
    cout << "It was a tie." << endl;
  }
  cout << endl;
}

int main()
{
  CardGame game(CardDeck{});

  game.initialize();
  game.play();
}