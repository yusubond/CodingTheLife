#include <iostream>
#include <cstring>
#include <algorithm>
#define M 3
#define N 3
using namespace std;

int MinFuc(int x, int y, int z) {
  return z < (x < y ? x : y) ? z : (x < y ? x : y);
}
int MinCost(int cost[M][N], int m, int n) {
  int res[M][N];
  res[0][0] = cost[0][0];
  if(m == 0 && n == 0)
    return res[0][0];
  int i, j;
  for(i = 1; i < M; i++)
    res[i][0] = res[i-1][0] + cost[i][0];
  for(j = 1; j < N; j++)
    res[0][j] = res[0][j - 1] + cost[0][j];
  for(i = 1; i <= m; i++)
    for(j = 1; j <= n; j++)
      res[i][j] = MinFuc(res[i-1][j], res[i-1][j-1], res[i][j-1]) + cost[i][j];
  return res[m][n];
}

int main() {
  int cost[M][N], m, n;
  for(int i = 0; i < M; i++)
    for(int j = 0; j < N; j++)
      cin >> cost[i][j];
  cin >> m >> n;
  cout << MinCost(cost, m, n) << endl;
  return 0;
}
