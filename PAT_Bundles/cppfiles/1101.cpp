#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int a[100010], b[100010];
vector<int> ans;
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(a, a + n);
  int temp = -1;
  for(int i = 0; i < n; i++) {
    if(a[i] == b[i] && temp < a[i]) {
      temp = a[i];
      ans.push_back(a[i]);
    }
    if(b[i] > temp)
      temp = b[i];
  }
  printf("%lu\n", ans.size());
  for(int i = 0; i < ans.size(); i++) {
    if(i == 0)
      printf("%d", ans[i]);
    else
      printf(" %d", ans[i]);
  }
  printf("\n");
  return 0;
}
