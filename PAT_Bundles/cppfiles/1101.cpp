#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[100005], b[100005];
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }
  sort(a, a + n);
  int v[100005];
  int max = 0;
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == b[i] && b[i] > max) {
      v[count++] = b[i];
    }
    if(max < b[i])  //保证前面的序列的最大值要小于当前值
      max = b[i];
  }
  printf("%d\n", count);
  for(int i = 0; i < count; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  printf("\n");
  return 0;
}
