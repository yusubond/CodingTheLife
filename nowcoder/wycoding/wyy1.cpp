#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> b, w;
bool cmp(int a, int b) {
  return a < b;
}
int main() {
  int n;
  cin >> n;
  b.resize(n);
  w.resize(n);
  char temp;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> temp;
      if(temp == 'B')
        b[j]++;
      if(temp == 'W')
        w[j]++;
    }
  }
  sort(b.begin(), b.end());
  sort(w.begin(), w.end());
  int res;
  if(b[b.size() - 1] > w[w.size() - 1])
    res = b[b.size() - 1];
  else
    res = w[w.size() - 1];
  cout << res;
  return 0;
}
