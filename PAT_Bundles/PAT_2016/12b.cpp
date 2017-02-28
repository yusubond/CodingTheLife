#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int couple[100000] = {-1};
int visit[100000] = {0};
int main() {
  int n, m, a, b;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    couple[a] = b;
    couple[b] = a;
  }
  scanf("%d", &m);
  int temp;
  vector<int> ans, v;
  for(int i = 0; i < m; i++) {
    scanf("%d", &temp);
    ans.push_back(temp);
    if(couple[temp] != -1) {
      visit[couple[temp]] = 1;
    }
  }
  for(int i = 0; i < ans.size(); i++) {
    if(visit[ans[i]] != 1)
      v.push_back(ans[i]);
  }
  sort(v.begin(), v.end());
  printf("%lu\n", v.size());
  for(int i = 0; i < v.size(); i++) {
    if(i == 0)
      printf("%05d", v[i]);
    else
      printf(" %05d", v[i]);
  }
  return 0;
}
