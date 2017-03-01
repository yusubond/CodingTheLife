#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, root;
double p, r, ans;
int maxdepth = -1;
vector<int> v[100010];
int book[100010];
void dfs(int x, int depth) {
  if(v[x].size() == 0) {
    book[depth]++;
    maxdepth = max(depth, maxdepth);
  }
  else {
    for(int i = 0; i < v[x].size(); i++)
      dfs(v[x]][i], depth + 1);
  }
}
int main() {
  scanf("%d %lf %lf", &n, &p, &r);
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    if(temp == -1)
      root = i;
    else
      v[temp].push_back(i);
  }
  dfs(root, 0);
  ans = p * pow((1.0 + r), maxdepth);
  printf("%.2lf %d", ans, book[maxdepth]);
  return 0;
}
