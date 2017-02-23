#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
  int n, m, temp, sum;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    v.push_back(temp);
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", &temp);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  sum = n + m;
  if(sum % 2 == 0) {
    sum = sum / 2 - 1;
  } else {
    sum = sum / 2;
  }
  printf("%d", v[sum]);
  return 0;
}
