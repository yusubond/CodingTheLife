#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v(m);
  for (int i = 0; i < m; ++i) cin >> v[i];
  sort(v.rbegin(), v.rend());
  int ret = v[0];
  int maxp = 0;
  int j0 = 0;
  for (int i = 0; i < min(n, m); ++i) {
    int c = v[i];
    if (c * (i + 1) >= maxp) {
      maxp = c * (i + 1);
      ret = c;
      j0 = i;
    }
  }
  if (j0 == n - 1 && j0 < m - 1 && v[j0] == v[j0 + 1]) {
    if (v[0] == ret) {
      ret++;
    } else {
    while(j0 >= 0 && v[j0] == ret) --j0;
    ret = v[j0];
    }
  }
  cout << ret << endl;
}
