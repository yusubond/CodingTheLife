#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int main() {
  string s, temps;
  cin >> s;
  temps = s;
  int len = s.length();
  int count1 = 0, count2 = 0;
  int res = 0;
  if(s[0] == 'G') {
    for(int j = 0; j < len; j++) {
      for(int i = len - 1 - j; i > 0; i--)
        if(s[i] == 'G' && s[i - 1] == 'B') {
          swap(s[i], s[i - 1]);
          count1++;
        }
      }
    for(int j = 0; j < len; j++) {
      for(int i = j; i < len - 1 -j; i++) {
        if(temps[i] == 'G' && temps[i + 1] == 'B') {
          swap(temps[i], temps[i + 1]);
          count2++;
        }
      }
    }
    res = count1 < count2 ? count1 : count2;
  }
  if(s[0] == 'B') {
    for(int j = 0; j < len; j++) {
      for(int i = len - 1 - j; i > 0; i--)
        if(s[i] == 'B' && s[i - 1] == 'G') {
          swap(s[i], s[i - 1]);
          count1++;
        }
      }
    for(int j = 0; j < len; j++) {
      for(int i = j; i < len - 1 -j; i++) {
        if(temps[i] == 'B' && temps[i + 1] == 'G') {
          swap(temps[i], temps[i + 1]);
          count2++;
        }
      }
    }
    res = count1 < count2 ? count1 : count2;
  }
  cout << res;;
  return 0;
}
