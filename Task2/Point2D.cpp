#include "Point2D.h"
#include <cmath>
#include <sstream>

Point2D::Point2D() : x(0), y(0) {}

Point2D::Point2D(float x, float y) : x(x), y(y) {}

Point2D::Point2D(Point2D const &ref) : x(ref.x), y(ref.y) {}

Point2D &Point2D::operator=(Point2D const &ref) {
  this->x = ref.x;
  this->y = ref.y;
  return *this;
}

float Point2D::distance(Point2D const &toPoint) const {
  float dx = this->x - toPoint.x;
  float dy = this->y - toPoint.y;
  return sqrt(dx * dx + dy * dy);
}

std::string Point2D::toString() const {
  std::stringstream ss;

  ss << "[" << this->x << ", " << this->y << "]";

  return ss.str();
}

Point2D Point2D::operator+(Point2D const &rhs) const {
  return Point2D{this->x + rhs.x, this->y + rhs.y};
}

bool Point2D::operator==(Point2D const &rhs) const {
  return this->x == rhs.x && this->y == rhs.y;
}
