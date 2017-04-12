#include <iostream>
#include <vector>
#include <string>
using namespace std;
string res(string &s) {
  for(int i = 0; i < s.size() / 2; i++)
    swap(s[i], s[s.size() - 1 - i]);
  return s;
}
int main() {
  string s;
  while(cin >> s) {
    res(s);
    cout << s << endl;
  }
  return 0;
}
