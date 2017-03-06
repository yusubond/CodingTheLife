#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> v(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  double ans = v[0];
  for(int i = 1; i < n; i++)
    ans = (ans + v[i]) / 2;
  printf("%d", int(ans));
  return 0;
}
