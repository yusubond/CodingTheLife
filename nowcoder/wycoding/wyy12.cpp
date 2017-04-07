#include <cstdio>
#include <vector>
#include <string.h>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> v;
vector<string> s;
int main() {
  int n;
  scanf("%d", &n);
  getchar();
  v.resize(n);
  s.resize(n);
  string temp;
  for(int i = 0; i < n; i++) {
    getline(cin, temp);
    s.push_back(temp);
    }
  }
  for(int i = 0; i < n; i++) {
    int temp = 0, m = 0;
    for(int j = 1; i < n; j++) {
      if(s[j][i] == s[j - 1][i]) {
        temp++;
      } else {
        temp = 0;
      }
      if(temp > m)
        m = temp;
    }
    v[i] = m;
  }
  sort(v.begin(), v.end());
  printf("%d", v[v.size() - 1]);
  return 0;
}
