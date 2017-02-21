#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
  int num1, num2;
};
bool cmp1 (node a, node b) {
  return a.num1 < b.num1;
}
bool cmp2(int a, int b) {
  return a < b;
}
int main() {
  int n, m, a, b, temp;
  scanf("%d", &n);
  struct node v[n];
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    if(a < b) {
      v[i].num1 = a;
      v[i].num2 = b;
    } else {
      v[i].num1 = b;
      v[i].num2 = a;
    }
  }
  sort(v, v + n, cmp1);
  scanf("%d", &m);
  int data[m];
  for(int i = 0; i < m; i++) {
    scanf("%d", &data[i]);
  }
  sort(data, data + m, cmp2);
  int count = m;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(data[i] == v[j].num1) {
        for(int k = i + 1; k < m; k++) {
          if(data[k] == v[j].num2) {
            data[i] = -1;
            data[k] = -1;
            count = count - 2;
          }
        }
      }
    }
  }
  //if(count == 0)
  //  printf("0\n");
  vector<int> result;
  for(int i = 0; i < m; i++) {
    if(data[i] > 0)
      result.push_back(data[i]);
  }
  printf("%d\n", result.size());
  for(int i = 0; i < result.size(); i++) {
    if(i == 0)
      printf("%d", result[i]);
    else
      printf(" %d", result[i]);
  }
  return 0;
}
