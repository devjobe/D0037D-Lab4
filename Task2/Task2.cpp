#include <iostream>

#include "Point2D.h"

using namespace std;

int main() {
  Point2D A(1, 2);
  Point2D B(4, 6);

  cout << "The distance from A: " << A.toString() << " to B: " << B.toString()
       << " is " << A.distance(B) << endl;

  Point2D C = A;
  cout << "The new point C: " << C.toString();

  if (C == A) {
    cout << " is equal to A ";
  } else {
    cout << " is not equal to A ";
  }

  if (C == B) {
    cout << " and B." << endl;
  } else {
    cout << " but to not B." << endl;
  }

  Point2D D = A + B;

  cout << "The sum of A and B is D: " << D.toString()
       << " which distance to A is " << D.distance(A) << "." << endl;

  if (D == A || D == B || D == C) {
    cout << "D is equal to one of the previous points." << endl;
  } else {
    cout << "D is not equal to any of previous points." << endl;
  }
  return 0;
}