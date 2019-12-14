#pragma once
#include<vector>
#include<algorithm>
#include "point.h"

using std::vector;
using std::min;

class Graph2D {
public:
  Graph2D(vector<Point> points) : points(points) {}
  double calculate_path_length(vector<int> order);
  double get_min();
  void print();
private:
  vector<Point> points;
  double get_min_recursive(vector<int>& order, size_t start_pos) {
    double min_val = calculate_path_length(order);
    for (size_t i = start_pos + 1; i < points.size(); i++) {
      std::swap(order[start_pos], order[i]);
      min_val = std::min(get_min_recursive(order, start_pos + 1), min_val);
      std::swap(order[start_pos], order[i]);
    }
    return min_val;
  }
};
