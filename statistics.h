#pragma once
#include<vector>

using std::vector;

class Statistics {
public:
  Statistics(vector<double> values);
  Statistics(const Statistics& other) = delete;
  Statistics& operator=(Statistics&& other)  = delete;
  Statistics& operator=(const Statistics& other) = delete;
  //~Statistics() = delete;
  double avg;
  double stddev;
  int size;
};

std::ostream &operator<<(std::ostream &os, Statistics const &m);
