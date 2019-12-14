#include"graph2d.h"
#include<algorithm>
#include<iostream>

using std::cout;

double Graph2D::calculate_path_length(vector<int> order) {
  double result = 0;
  for (size_t i = 0; i < order.size() - 1; i++) {
    result += points[order[i]].distance(points[order[i + 1]]);
  }
  result += points[order[0]].distance(points[order[order.size() - 1]]);
  return result;
}

double Graph2D::get_min() {
  vector<int> order;
  for (size_t i = 0; i < points.size(); i++) {
    order.push_back(i);
  }
  return get_min_recursive(order, 0);
}

void Graph2D::print() {
  for (int i = 0; i < points.size(); i++) {
    cout << points[i];
  }
}
