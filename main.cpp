//
// Created by Kylian Lee on 2021/05/08.
//
#include <iostream>
#include <vector>

using namespace std;

double solution(int city ,int pt);

vector<vector<int>> roads;

int main() {
  int cities, src, dest;
  cin >> cities;
  roads.resize(cities + 1);
  roads[1].push_back(0);
  for (int i = 1; i < cities; i++) {
    cin >> src >> dest;
    roads[src].push_back(dest);
    roads[dest].push_back(src);
  }
  double answer = solution(1, 0);
  cout.precision(10);
  cout << answer << endl;
}
double solution(int city, int pt) {
//  cout << "city : " << city << endl;
  int roadNum = roads[city].size();
  if (roadNum == 1)
    return 0.0;
  double sum = 0.0;
  for (int i = 0; i < roadNum; i++) {
    if(roads[city][i] == pt)
      continue;
    sum += 1.0;
    sum += solution(roads[city][i], city);
  }
//  cout << "sum : " << sum << endl;
  return sum / (roadNum - 1);
}
