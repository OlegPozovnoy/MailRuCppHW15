#include"kruskal.h"
#include <iostream>
#include<map>
#include<vector>
#include<algorithm>
#include <queue>
#include<set>

using std::vector;
using std::cin;
using std::cout;
using std::map;
using std::min;
using std::max;
using std::queue;
using std::priority_queue;

struct CustomCompare
{
  bool operator()(const veh& lhs, const veh& rhs)
  {
    return lhs.weigh > rhs.weigh;
  }
};

int get_root(const vector<int>& a, int index, int& iterations) {
  iterations = 0;
  while (a[index] != index) {
    index = a[index];
    iterations++;
  }
  return index;
}

// n - число вершин
vector<veh> get_ostov(vector<veh> rebra, int n) {
  vector<veh> result_ostov;

  priority_queue<veh, vector<veh>, CustomCompare> weigh;
  int v = rebra.size();

  vector<int> subgraph(n);
  for (auto i = 0; i < n; i++) {
    subgraph[i] = i;
  }

  // v1, v2 - вершины, w - длина
  for (size_t i = 0; i < rebra.size(); i++) {
    weigh.push({ min(rebra[i].start,rebra[i].end), max(rebra[i].start,rebra[i].end), rebra[i].weigh });
  }

  //double result = 0;
  for (auto i = 0; i < n - 1; i++) {
    veh top;
    int left_root;
    int left_iterations;
    int right_root;
    int right_iterations;
    do {
      top = weigh.top();
      weigh.pop();
      left_root = get_root(subgraph, top.start, left_iterations);
      right_root = get_root(subgraph, top.end, right_iterations);
    } while (left_root == right_root);
    //result += top.weigh;
    result_ostov.push_back(top);

    int from = subgraph[top.end];
    int to = subgraph[top.start];

    if (left_iterations < right_iterations) {
      subgraph[left_root] = right_root;
    }
    else {
      subgraph[right_root] = left_root;
    }
  }
  return result_ostov;
}

vector<int> get_hamilton_cycle_from_ostov(vector<veh> ostov, int size) {
  map<int, vector<int>> graph;
  vector<bool> visited(size, false);
  vector<int> dfs;
  vector<int> result;

  for (size_t i = 0; i < ostov.size(); i++) {
    graph[ostov[i].start].push_back(ostov[i].end);
    graph[ostov[i].end].push_back(ostov[i].start);
  }
  queue<int> graph_queue;
  dfs.push_back(0);
  while (dfs.size() > 0) {
    int current = dfs.back();
    dfs.pop_back();
    if (visited[current] == false)
    {
      visited[current] = true;
      result.push_back(current);
    }
    for (auto element : graph[current]) {
      if (visited[element] == false) {
        dfs.push_back(element);
      }
    }
  }
  return result;
}
