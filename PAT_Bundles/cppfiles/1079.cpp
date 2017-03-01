#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[100010];
vector<int> vv;
int book[100010];
void dfs(int x, int depth) {
  if(v[x].size() == 0) {
    book[x] = depth;
    return ;
  } else {
    for(int i = 0; i < v[x].size(); i++)
      dfs(v[x][i], depth + 1);
  }
}
int main() {
  int n, k, temp;
  double p, r, ans = 0.0;
  scanf("%d %lf %lf", &n, &p, &r);
  int sum[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &k);
    if(k != 0) {
      for(int j = 0; j < k; j++)
      scanf("%d", &temp);
      v[i].push_back(temp);
    } else {
      scanf("%d", &temp);
      sum[i] = temp;
      vv.push_back(i);
    }
  }
  dfs(0, 0);
  for(int i = 0; i < vv.size(); i++) {
    ans += p * pow((1 + r / 100), book[vv[i]]) * sum[vv[i]];
  }
  printf("%.1lf", ans);
  return 0;
}
