#pragma once

#include <string>
#include <optional>

#include "Input.h"

struct Body {
  Body(std::string color, float width, float height);

  void print() const;

  std::string color;
  float width;
  float height;
};


std::optional<Body> bodyFrom(util::Input& input);