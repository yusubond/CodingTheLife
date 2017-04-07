#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
  int n, m;
  while(cin >> n >> m) {
    vector<int> v;
    for(int i = n; i <= m; i++) {
      int a = i / 100;
      int b = i % 100 / 10;
      int c = i % 10;
      if(i == pow(a,3) + pow(b, 3) + pow(c, 3))
        v.push_back(i);
    }
    if(v.size() == 0)
      printf("no\n");
    else {
      for(int i = 0; i < v.size(); i++)
        if(i == v.size() - 1)
          printf("%d", v[i]);
        else
          printf("%d ", v[i]);
      printf("\n");
    }
    v.clear();
  }
  return 0;
}
