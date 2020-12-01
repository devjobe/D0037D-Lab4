#pragma once

#include <optional>

struct Engine {
  Engine(float sizeInLiters, int numberOfCylinders);

  void print() const;

  float sizeInLiters;
  int numberOfCylinders;
};

std::optional<Engine> engineFromStdio();