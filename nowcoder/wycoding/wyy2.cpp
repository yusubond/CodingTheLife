#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int main() {
  string s, temps;
  cin >> s;
  int len = s.length();
  int count = 0;
  if(s[0] == 'G') {
    for(int j = 0; j < len; j++) {
      for(int i = len - 1 - j; i > 0; i--)
        if(s[i] == 'G' && s[i - 1] == 'B') {
          swap(s[i], s[i - 1]);
          count++;
        }
      }
  }
  if(s[0] == 'B') {
    for(int j = 0; j < len; j++) {
      for(int i = len - 1 - j; i > 0; i--)
        if(s[i] == 'B' && s[i - 1] == 'G') {
          swap(s[i], s[i - 1]);
          count++;
        }
      }
  }
  cout << count;
  return 0;
}
