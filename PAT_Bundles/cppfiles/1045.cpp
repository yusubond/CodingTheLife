#include <cstdio>
#include <algorithm>
using namespace std;
int book[210], a[10010], dp[10010];
int main() {
  int n, m, l, x;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= m; i++) {
    scanf("%d", &x);
    book[x] = i;
  }
  scanf("%d", &l);
  int sum = 0, maxn = 0;
  for(int i = 0; i < l; i++) {
    scanf("%d", &x);
    if(book[x] >= 1) {
      a[sum++] = book[x];
    }
  }
  for(int i = 0; i < sum; i++) {
    dp[i] = 1;
    for(int j = 0; j < i; j++) {
      if(a[j] <= a[i])
        dp[i] = max(dp[i], dp[j] + 1);
    }
    maxn = max(maxn, dp[i]);
  }
  printf("%d", maxn);
  return 0;
}
