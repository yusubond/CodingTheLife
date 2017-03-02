#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int getn(int num) {
  int n = sqrt(num * 1.0);
  while(num % n != 0) {
    n--;
  }
  return n;
}
bool cmp(int a, int b) {
  return a > b;
}
int main() {
  int N, m, n;
  vector<int> v;
  scanf("%d", &N);
  v.resize(N);
  for(int i = 0; i < N; i++)
    scanf("%d", &v[i]);
  sort(v.begin(), v.end(), cmp);
  n = getn(N);  //列
  m = N / n;  //行
  int ans[m][n];
  int t = 0;
  for(int i = 0; i < (m / 2 + m % 2); i++) {
    for(int j = i; j <= n - 1 - i && t <= N - 1; j++)
      ans[i][j] = v[t++];
    for(int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
      ans[j][n - i - 1] = v[t++];
    for(int j = n - i - 1; j >= i && t <= N - 1; j--)
      ans[m - i - 1][j] = v[t++];
    for(int j = m - i - 2; j >= i + 1 && t <= N - 1; j--)
      ans[j][i] = v[t++];
  }
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(j == 0)
        printf("%d", ans[i][j]);
      else
        printf(" %d", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
