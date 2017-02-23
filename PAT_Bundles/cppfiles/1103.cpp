#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, k, p, maxfacsum = -1;
vector<int> v, ans, tempans;
void init() {
  int temp = 0, index = 1;
  while(temp <= n) {
    v.push_back(temp);
    temp = pow(index, p);
    index++;
  }
}
void dfs(int index, int tempsum, int tempk, int facsum) {
  if(tempsum == n && tempk == k) {
    if(maxfacsum < facsum) {
      maxfacsum = facsum;
      ans = tempans;
    }
    return;
  }
  if(tempsum > n || tempk > k) return;
  if(index >= 1) {
    tempans.push_back(index);
    dfs(index, tempsum + v[index], tempk + 1, facsum + index);
    tempans.pop_back();
    dfs(index - 1, tempsum, tempk, facsum);
  }
}
int main() {
  scanf("%d %d %d", &n, &k, &p);
  init();
  dfs(v.size() - 1, 0, 0, 0);
  if(maxfacsum == -1) {
    printf("Impossible\n");
    return 0;
  }
  printf("%d = ", n);
  for(int i = 0; i < ans.size(); i++) {
    if(i != 0)
      printf(" + ");
    printf("%d^%d", ans[i], p);
  }
  return 0;
}
