#include<math.h>
#include<iostream>
#include "point.h"

constexpr double pi = 3.14159265358979323846;

Point::Point() {
  double r = ((double)rand() + 1.) / (static_cast<double>(RAND_MAX) + 1.);
  double phi = ((double)rand() + 1.) / (static_cast<double>(RAND_MAX) + 1.);
  X = cos(2 * pi * phi) * -2 * log(r);
  Y = sin(2 * pi * phi) * -2 * log(r);
}

double Point::distance(const Point& rh) const {
  return sqrt((X - rh.X)*(X - rh.X) + (Y - rh.Y) * (Y - rh.Y));
}

std::ostream &operator<<(std::ostream &os, Point const &m) {
  os << "X: " << m.X << " Y: " << m.Y << std::endl;
  return os;
}
