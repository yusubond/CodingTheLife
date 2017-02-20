#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int func(int N) {
  int i = sqrt((double)N);
  while(i >= 1) {
      if(N % i == 0)
          return i;
      i--;
  }
  return 1;
}

int cmp(int a, int b) {return a > b;}

int main() {
  int N, m, n, t = 0;
  scanf("%d", &N);
  n = func(N);
  m = N / n;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
      scanf("%d", &a[i]);
  sort(a.begin(), a.end(), cmp);
  vector<vector<int> > b(m, vector<int>(n));
  int level = m / 2 + m % 2;
  for (int i = 0; i < level; i++) {
    //向右
    for(int j = i; j <= n - 1 - i && t <= N - 1; j++)
      b[i][j] = a[t++];
    //向下
    for(int j = i + 1; j <= m - 1 - i - 1 && t <= N - 1; j++)
      b[j][n - 1 - i] = a[t++];
    //向左
    for(int j = n - 1 - i; j >= i && t <= N - 1; j--)
      b[m - 1 - i][j] = a[t++];
    //向上
    for(int j = m - 1 - i - 1; j >= i + 1 && t <= N - 1; j--)
      b[j][i] = a[t++];
  }
  for (int i = 0; i < m; i++) {
      for (int j = 0 ; j < n; j++) {
          printf("%d", b[i][j]);
          if (j != n - 1) printf(" ");
      }
      printf("\n");
  }
  return 0;
}
