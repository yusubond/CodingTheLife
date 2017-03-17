#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
bool cmp(string s1, string s2) {
  return s1 > s2;
}
int n;
int main() {
  cin >> n;
  vector<string> v(n);
  string temp, rtemp;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    rtemp.assign(temp.rbegin(), temp.rend());
    if(temp < rtemp)
      v[i] = rtemp;
    else
      v[i] = temp;
  }
  int flag = 0;
  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < n; i++) {
    cout << v[i] << endl;
  }
  cout << v[0][0];
  v[0] = string(v[0].begin() + 1, v[0].end());
  if(v[0].length() == v[1].length() && v[0] < v[1]) {
    cout << v[1];
    flag = 1;
  } else {
    cout << v[0] << v[1];
  }
  for(int i = 2; i < v.size(); i++) {
    cout << v[i];
  }
  if(flag) {
    string tempend;
    tempend.assign(v[0].rbegin(), v[0].rend());
    cout << tempend;
  }
  return 0;
}
