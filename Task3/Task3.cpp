#include <iostream>

#include "Polyline.h"

using namespace std;


void test_polyline(Polyline &p) {

  cout << "Testing: ";
  p.print();
  cout << "Total line length is " << p.totalLineLength() << "." << endl;
  cout << "Number of points is " << p.numberOfPoints() << "." << endl;

  if (p.numberOfPoints() > 1)
    cout << "The second point is " << p[1].toString() << "." << endl;

  Point2D A(4, -4);
  if (p.contains(A)) {
    cout << "It contains ";
  } else {
    cout << "It does not contain ";
  }
  cout << A.toString() << endl;

  Point2D B(8, 9);
  if (p.contains(B)) {
    cout << "It contains ";
  } else {
    cout << "It does not contain ";
  }
  cout << B.toString() << endl;

  Point2D C(2, 2);

  if (p.append(C)) {
    cout << "Adding a point was successful." << endl;
  } else {
    cout << "Adding a point was not successful." << endl;
  }

  if (p.removeLastPoint()) {
    cout << "Removing last point was successful. The number of points is now "
         << p.numberOfPoints() << "." << endl;
  } else {
    cout << "Removing the last point was not successful." << endl;
  }

  if (p.removeLastPoint()) {
    cout
        << "Removing another point was successful. The number of points is now "
        << p.numberOfPoints() << "." << endl;
  } else {
    cout << "Removing another point was not successful." << endl;
  }
  cout << "End testing: ";
  p.print();
  cout << endl;
}

int main() {
  {
    Polyline p(5);

    p.append(Point2D(1, 1));
    p.append(Point2D(5, 4));
    p.append(Point2D(5, -4));
    p.append(Point2D(8, 9));
    p.append(Point2D(9, 0));

    test_polyline(p);
  }
  {
    Polyline p(0);
    test_polyline(p);
  }

  return 0;
}

