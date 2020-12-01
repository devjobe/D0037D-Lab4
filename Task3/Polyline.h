#pragma once

#include "../Task2/Point2D.h"


class Polyline {
  Point2D **const points;
  int count;
  int const capacity;

public:
  Polyline(int capacity);
  ~Polyline();

  Polyline(Polyline const &) = delete;
  Polyline &operator=(Polyline const &) = delete;

  bool append(Point2D const &pt);
  Point2D &operator[](int n) const;
  bool removeLastPoint();
  bool contains(Point2D const &pt) const;
  int numberOfPoints() const;
  float totalLineLength() const;
  void print() const;
};

