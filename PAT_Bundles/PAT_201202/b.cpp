#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string s;
void add() {
  int len = s.length();
  string t = s;
  reverse(t.begin(), t.end());
  int flag = 0;
  for(int i = 0; i < len; i++){
    //s[i] += t[i] + flag - '0';    //一定需要'0',通过相对位置计算
    //flag = 0;
    //if(s[i] > '9') {
    //  s[i] = s[i] - 10;
    //  flag = 1;
    //}
    int temp = (s[i] - '0') + (t[i] - '0') + flag;
    flag = 0;
    if(temp >= 10) {
      temp = temp - 10;
      flag = 1;
    }
    s[i] = temp + '0';
  }
  if(flag)
    s += '1';
  reverse(s.begin(), s.end());
}
int main() {
  int count;
  cin >> s >> count;
  for(int i = 0; i <= count; i++) {
    string t = s;
    reverse(t.begin(), t.end());
    if(t == s) {
      cout << s << endl << i;
      return 0;
    }
    if(i != count)
      add();
  }
  cout << s << endl << count;
  return 0;
}
