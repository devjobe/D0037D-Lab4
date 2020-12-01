#pragma once

#include <string>

struct Point2D {
  float x;
  float y;

  Point2D();
  Point2D(float x, float y);
  Point2D(Point2D const &ref);

  Point2D &operator=(Point2D const &ref);

  float distance(Point2D const &toPoint) const;
  std::string toString() const;

  Point2D operator+(Point2D const &rhs) const;
  bool operator==(Point2D const &rhs) const;
};



