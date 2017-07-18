#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int MinFuc(int x, int y, int z) {
  return z < (x < y ? x : y) ? z : (x < y ? x : y);
}
int EditDistance(string s1, string s2, int n, int m) {
  if(n == 0)
    return m;
  if(m == 0)
    return n;
  if(s1[n - 1] == s2[m - 1])
    return EditDistance(s1, s2, n - 1, m - 1);
  else
    // 插入、删除，替换
    return 1 + MinFuc(EditDistance(s1, s2, n, m - 1), EditDistance(s1, s2, n - 1, m), EditDistance(s1, s2, n - 1, m - 1));
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << s1 << endl;
  cout << s2 << endl;
  cout << EditDistance(s1, s2, s1.length(), s2.length()) << endl;
  return 0;
}
