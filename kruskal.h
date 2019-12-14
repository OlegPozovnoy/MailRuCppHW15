#pragma once
#include<vector>

using std::vector;

struct veh {
  int start;
  int end;
  double weigh;
};

vector<veh> get_ostov(vector<veh> rebra, int n);
vector<int> get_hamilton_cycle_from_ostov(vector<veh> ostov, int size);
