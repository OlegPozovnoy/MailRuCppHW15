#pragma once
#include<vector>

using std::vector;

class Statistics {
public:
  Statistics(vector<double> values);
  double avg;
  double stddev;
  int size;
};

std::ostream &operator<<(std::ostream &os, Statistics const &m);
