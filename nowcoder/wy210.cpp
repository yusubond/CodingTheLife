#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> v;
int main() {
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  int temp = 0;
  for(int i = 0; i < n; i++) {
    temp += v[i];
    if(v[i + 1] > temp + 1)
      cout << temp + 1;
  }
  return 0;
}
