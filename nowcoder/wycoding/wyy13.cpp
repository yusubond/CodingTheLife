#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> b, w, v;
bool cmp(int a, int b) {
  return a < b;
}
int main() {
  int n;
  cin >> n;
  b.resize(n);
  w.resize(n);
  v.resize(n);
  char temp;
  char c[55][55];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> temp;
      c[i][j] = temp;
      if(temp == 'B')
        b[j]++;
      if(temp == 'W')
        w[j]++;
    }
  }
  for(int i = 0; i < n; i++) {
    int temp = 0, m = 0;
    for(int j = 1; i < n; j++) {
      if(c[j][i] == c[j - 1][i]) {
        temp++;
      } else {
        temp = 0;
      }
      if(temp > m)
        m = temp;
    }
    v[i] = m;
  }
  sort(b.begin(), b.end());
  sort(w.begin(), w.end());
  sort(v.begin(), v.end());
  int res;
  if(b[b.size() - 1] > w[w.size() - 1])
    res = b[b.size() - 1];
  else
    res = w[w.size() - 1];
  cout << res;
  cout << v[v.size() - 1];
  return 0;
}
