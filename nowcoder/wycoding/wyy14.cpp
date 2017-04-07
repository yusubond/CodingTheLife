#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
bool cmp(int a, int b) {
  return a < b;
}
int main() {
  int n;
  cin >> n;
  v.resize(n);
  char temp;
  char c[55][55];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> temp;
      c[i][j] = temp;
    }
  }
  for(int i = 0; i < n; i++) {
    int t = 0, m = 0;
    for(int j = 0; j < n - 1; j++) {
      if(c[j][i] == c[j + 1][i]) {
        t++;
      } else {
        t = 0;
      }
      if(t > m)
        m = t;
    }
    v[i] = m;
  }
  sort(v.begin(), v.end());
  cout << (v[n - 1] + 1);
  return 0;
}
