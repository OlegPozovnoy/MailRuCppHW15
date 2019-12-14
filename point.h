#pragma once

class Point {
  public:
    Point();
    double distance(const Point& rh) const;
    double X;
    double Y;
};

std::ostream &operator<<(std::ostream &os, Point const &m);
