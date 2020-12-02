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

std::optional<Body> bodyFrom(util::Input &input) {

  auto color = input.prompt("Body color: ").line();
  if (!color.size()) {
    return {};
  }
  auto width = in_range({std::numeric_limits<float>::epsilon(), {}},
                        input.prompt("Body width: ").only<float>());
  if (!width) {
    return {};
  }
  auto height = in_range({std::numeric_limits<float>::epsilon(), {}},
                         input.prompt("Body height: ").only<float>());
  if (!height) {
    return {};
  }

  return Body{std::move(color), *width, *height};
}
