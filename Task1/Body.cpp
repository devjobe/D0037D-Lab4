#include <iostream>
#include <iomanip>

#include "Body.h"
#include "Input.h"

using namespace std;
using namespace util;



Body::Body(std::string color, float width, float height)
    : color(color), width(width), height(height) {}

void Body::print() const {
  cout.precision(2);
  cout << "The body is " << this->color << " and measures, " << fixed
       << this->width << " (m) wide and " << this->height << " (m) tall.\n";
}

std::optional<Body> bodyFromStdio() {

  auto color = input_line("Body color: ");
  if (!color.size()) {
    return {};
  }
  auto width = in_range({0.0f, {}}, input_f32("Body width: "));
  if (!width) {
    return {};
  }
  auto height = in_range({0.0f, {}}, input_f32("Body height: "));
  if (!height) {
    return {};
  }

  return Body{ std::move(color), *width, *height};
}
