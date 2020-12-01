#include <iostream>

#include "CardDeck.h"

using namespace std;

int main() {
  CardDeck deck;
  std::cout << "The deck contains:" << endl;
  deck.print();
  return 0;
}
