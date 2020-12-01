#pragma once

#include <string>
#include <optional>

struct Body {
  Body(std::string color, float width, float height);

  void print() const;

  std::string color;
  float width;
  float height;
};


std::optional<Body> bodyFromStdio();