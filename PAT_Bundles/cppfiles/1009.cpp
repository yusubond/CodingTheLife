#include <iostream>
using namespace std;
int main() {
  int n1, n2, temp;
  double v1[1001] = {0.0}, v2[1001] = {0.0}, v3[2001] = {0.0};
  cin >> n1;
  for(int i = 0; i < n1; i++) {
    cin >> temp;
    cin >> v1[temp];
  }
  cin >> n2;
  for(int i = 0;i < n2; i++) {
    cin >> temp;
    cin >> v2[temp];
  }
  for(int i = 1001; i >= 0; i--) {
    if(v1[i] != 0.0) {
      for(int j = 1001; j >=0; j--) {
        if(v2[j] != 0.0) {
          v3[i + j] += v1[i] * v2[j];
        }
      }
    }
  }
  int c = 0;
  for(int i = 2001; i >= 0; i--) {
    if(v3[i] > 0)
      c++;
  }
  cout << c;
  for (int i = 2001; i >= 0; i--) {
    if(v3[i] != 0.0)
      cout << " " << i << " "<< v3[i];
  }
  return 0;
}

//参考答案
//www.liuchuo.net/archives/2026
#include <cstdio>
using namespace std;
int main() {
  int n1, n2, tmp, cnt = 0;
  double b;
  scanf("%d", &n1);
  double arr[1001] = {0.0};
  double ans[2001] = {0.0};
  for(int i = 0; i < n1; i++) {
    scanf("%d %lf", &tmp, &b);
    arr[tmp] = b;
  }
  scanf("%d", &n2);
  for(int i = 0; i < n2; i++) {
    scanf("%d %lf\n", &tmp, &b);
    for(int j = 0; j < 1001; j++) {
      if(arr[j] != 0.0) {
        ans[j + tmp] += arr[j] * b;
      }
    }
  }
  for(int i = 2000; i >= 0; i--) {
    if(ans[i] != 0.0) {
      cnt++;
    }
  }
  printf("%d", cnt);
  for(int i = 2000; i >= 0; i--) {
    if(ans[i] != 0.0) {
      printf(" %d %.lf\n", i, ans[i]);
    }
  }
  return 0;
}
