/*
«Приближенное решение метрической неориентированной задачи коммивояжера».Найдите приближенное решение метрической неориентированной задачи коммивояжера в полном графе(на плоскости) с помощью минимального остовного дерева.
Оцените качество приближения на случайном наборе точек, нормально распределенном на плоскости с дисперсией 1. Нормально распределенный набор точек получайте с помощью преобразования Бокса - Мюллера.
При фиксированном N, количестве вершин графа, несколько раз запустите оценку качества приближения.Вычислите среднее значение и среднеквадратичное отклонение качества приближения для данного N.
Запустите данный эксперимент для всех N в некотором диапазоне, например, [2, 10].
Автоматизируйте запуск экспериментов.
В решении требуется разумно разделить код на файлы.Каждому классу - свой заголовочный файл и файл с реализацией.
*/

#include <iostream>
#include "statistics.h"
#include "kruskal.h"
#include "graph2d.h"
#include<queue>
#include<map>

using std::cout;
using std::cin;
using std::queue;
using std::map;
using std::pair;

pair<double, double> getIteratoin(int n) {
  vector<Point> vec;  
  for (int i = 0; i < n; i++) {
    vec.push_back(Point());
  }
  Graph2D graph(vec);
  //graph.print();

  double optimal_result =  graph.get_min();
  //cout << "Optimal value" << optimal_result<<std::endl;

  vector<veh> kruskal;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      veh tmp;
      tmp.start = j;
      tmp.end = i;
      tmp.weigh = vec[i].distance(vec[j]);
      kruskal.push_back(tmp);
    }
  }
  vector<veh> ostov = get_ostov(kruskal, n);
  vector<int> hamilton = get_hamilton_cycle_from_ostov(ostov,n);
  double ostov_result = graph.calculate_path_length(hamilton);
  //cout << "Ostov value" << ostov_result << std::endl;
  // возвращаем отклонение в процентах
  return std::make_pair(ostov_result,optimal_result);
}

int main()
{
  //int n;
  int size = 100;
  //cout << "Введите число вершин графа:";
  //cin >> n;
  //cout << "Введите число итераций:";
  //cin >> size;


  for (int n = 3; n <= 10; n++) {
    vector<double> relative_pct;
    vector<double> ostov_results;
    vector<double> optimal_results;
    for (int i = 0; i < size; i++) {
      pair<double, double> result = getIteratoin(n);
      ostov_results.push_back(result.first);
      optimal_results.push_back(result.second);
      relative_pct.push_back((result.first / result.second - 1) * 100);
    }
    Statistics relative_stat(relative_pct);
    Statistics ostov_stat(ostov_results);
    Statistics optimal_stat(optimal_results);
    cout << "For n = " << n<< std::endl;
    cout << "Ostov: " << ostov_stat;// << std::endl;
    cout << "Optimal: " << optimal_stat;// << std::endl;
    cout << "Pct.difference: " << relative_stat;// << std::endl;
  }

  getchar();
}
