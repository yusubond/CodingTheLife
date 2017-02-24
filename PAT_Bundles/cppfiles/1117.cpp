#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
  return a > b;
}
int main() {
  int n, temp;
  vector<int> v;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    v.push_back(temp);
  }
  sort(v.begin(), v.end(), cmp);
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(v[i] > i + 1)
      count++;
    else
      break;
  }
  printf("%d", count);
  return 0;
}
