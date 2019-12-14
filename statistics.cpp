#include"statistics.h"
#include<iostream>

Statistics::Statistics(vector<double> values) {
  double sum = 0;
  for (size_t i = 0; i < values.size(); i++) {
    sum += values[i];
  }

  avg = sum / values.size();
  stddev = 0;
  for (size_t i = 0; i < values.size(); i++) {
    stddev += (values[i] - avg)*(values[i] - avg);
  }

  stddev /= (values.size() - 1);
  stddev = sqrt(stddev);
  size = values.size();
}

std::ostream &operator<<(std::ostream &os, Statistics const &m) {
  os << "Avg: " << m.avg << " StdDev: " << m.stddev << " Size: " << m.size << std::endl;
  return os;
}
