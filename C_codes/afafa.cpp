#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 10; // maximum number of cities
int N; // number of cities
double dist[MAX_N][MAX_N]; // distance matrix

double tsp(int pos, int visited, vector<int>& path) {
  if (visited == (1 << N) - 1) {
    return 0; // all cities visited
  }
  double best = 1e9;
  int best_next = -1;
  for (int i = 0; i < N; i++) {
    if (visited & (1 << i)) {
      continue; // already visited
    }
    path.push_back(i);
    double cost = dist[pos][i] + tsp(i, visited | (1 << i), path);
    if (cost < best) {
      best = cost;
      best_next = i;
    }
    path.pop_back();
  }
  if (best_next != -1) {
    path.push_back(best_next);
  }
  return best;
}

int main() {
  // read input
  cout<< "enter number of nodes: ";
  cin >> N;

  cout<< "enter the cost: ";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> dist[i][j];
    }
  }

  // find the shortest path
  double ans = 1e9;
  vector<int> path;
  for (int i = 0; i < N; i++) {
    path.push_back(i);
    double cost = tsp(i, 1 << i, path);
    if (cost < ans) {
      ans = cost;
    }
    path.pop_back();
  }

  // output the result
  cout << "Shortest path length: " << ans << endl;
  cout << "Path: ";
  path.push_back(0);
  for (int i = 0; i < N-1; i++) {
    int city1 = path[i];
    int city2 = path[i+1];
    cout << city1 << " -> ";
  }
  cout << path.back() << endl;

  return 0;
}
