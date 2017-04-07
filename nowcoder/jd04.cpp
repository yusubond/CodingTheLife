#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
  int v, p;
  int mem[2];
};
bool cmp(node a, node b) {
  if(a.v != b.v)
    return a.v > b.v;
  else
    return a.p > b.p;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<node> v(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i].v >> v[i].p;
    v[i].mem[0] = i + 1;
  }
  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < n; i++)
    cout << v[i].v << " " << v[i].p << " " << v[i].mem[0] << endl;
  return 0;
}
