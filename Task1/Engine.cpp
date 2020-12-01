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

std::optional<Engine> engineFromStdio() {
  auto sizeInLiters =
      in_range({0.0f, {}}, input_f32("Engine volume in liters: "));
  if (!sizeInLiters) {
    return {};
  }

  auto numberOfCylinders =
      in_range({0, {}}, input_i32("Number of cylinders: "));
  if (!numberOfCylinders) {
    return {};
  }

  return Engine{*sizeInLiters, *numberOfCylinders};
}
