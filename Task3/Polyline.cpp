#include <algorithm>
#include <iostream>
#include <numeric>

#include "Polyline.h"


Polyline::Polyline(int capacity)
    : points(new Point2D *[capacity]), count(0), capacity(capacity) {
  memset(points, 0, sizeof(Point2D *) * capacity);
}

Polyline::~Polyline() {
  std::for_each(points, points + count, [](auto p) { delete p; });
  delete[] points;
}

bool Polyline::append(Point2D const &pt) {
  if (count >= capacity)
    return false;

  this->points[count++] = new Point2D(pt);
  return true;
}

Point2D &Polyline::operator[](int n) const {
  if (n < 0 || n >= count) {
    std::cout << "Error in Polyline::operator[] index out of range."
              << std::endl;
    std::exit(EXIT_FAILURE);
  }

  return *(this->points[n]);
}

bool Polyline::removeLastPoint() {
  if (count <= 0)
    return false;
  delete this->points[--this->count];
  this->points[this->count] = nullptr;
  return true;
}

bool Polyline::contains(Point2D const &pt) const {
  for (int i = 0; i < this->numberOfPoints(); i++) {
    if ((*this)[i] == pt) {
      return true;
    }
  }
  return false;
}

int Polyline::numberOfPoints() const { return this->count; }

float Polyline::totalLineLength() const {
  float sum = .0f;
  int n = this->numberOfPoints() - 1;
  for (int i = 0; i < n; i++) {
    sum += (*this)[i].distance((*this)[i + 1]);
  }
  return sum;
}

void Polyline::print() const {
  std::cout << "Polyline[" << this->count << "/" << this->capacity << "] {";
  std::for_each(this->points, this->points + this->count,
                [](auto p) { std::cout << " " << p->toString(); });
  std::cout << " }" << std::endl;
}
