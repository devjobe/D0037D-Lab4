#include "Engine.h"

#include <iostream>
#include <iomanip>

#include "Input.h"

using namespace std;
using namespace util;

Engine::Engine(float sizeInLiters, int numberOfCylinders)
    : sizeInLiters(sizeInLiters), numberOfCylinders(numberOfCylinders) {}

void Engine::print() const {
  cout.precision(1);
  cout << fixed << this->sizeInLiters << "L " << this->numberOfCylinders
       << " cylinder engine.\n";
}

std::optional<Engine> engineFrom(util::Input &input) {
  auto sizeInLiters = in_range(
      {0.0f, {}}, input.prompt("Engine volume in liters: ").only<float>());
  if (!sizeInLiters) {
    return {};
  }

  auto numberOfCylinders =
      in_range({0, {}}, input.prompt("Number of cylinders: ").only<int>());
  if (!numberOfCylinders) {
    return {};
  }

  return Engine{*sizeInLiters, *numberOfCylinders};
}