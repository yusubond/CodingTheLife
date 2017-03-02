#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int n;
double p, r, ans;
vector<int> v[100010];
int mindepth = 99999999;
int t = 0;
void dfs(int node, int depth) {
  if(v[node].size() == 0) {
    if(depth < mindepth) {
      mindepth = depth;
      t = 1;
    } else if(depth == mindepth) {
      t++;
    }
    return ;
  }
  for(int i = 0; i < v[node].size(); i++) {
    dfs(v[node][i], depth + 1);
  }
}
int main() {
  scanf("%d %lf %lf", &n, &p, &r);
  r = r / 100;
  int k, temp;
  for(int i = 0; i < n; i++) {
    scanf("%d", &k);
    if(k == 0)
      continue;
    else {
      for(int j = 0; j < k; j++) {
        scanf("%d", &temp);
        v[i].push_back(temp);
      }
    }
  }
  dfs(0, 0);
  printf("%.4lf %d", p * pow((1 + r), mindepth), t);
  return 0;
}
