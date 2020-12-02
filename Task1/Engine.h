#pragma once

#include "Input.h"

struct Engine {
  Engine(float sizeInLiters, int numberOfCylinders);

  void print() const;

  float sizeInLiters;
  int numberOfCylinders;
};

std::optional<Engine> engineFrom(util::Input& input);