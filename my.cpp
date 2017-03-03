#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
using namespace std;
int main() {
  freopen("/Users/subond/Documents/MyLife/PATest/input", "r", stdin);
  freopen("/Users/subond/Documents/MyLife/PATest/output", "w", stdout);
  string s;
  cin >> s;
  int len = s.length() + 2;
  int n1, n2, n3;
  if(len % 3 == 0) {
    n1 = n2 = n3 = len % 3;
  } else {
    n2 = len / 3 + len % 3;
    n1 = n3 = (len - n2) / 2;
  }
  char ans[n1][n2];
  int t = 0;
  for(int i = 0; i < n1; i++)
    for(int j = 0; j < n2; j++)
      ans[i][j] = ' ';
  for(int i = 0; i <= n1 - 2; i++)
    ans[i][0] = s[t++];
  for(int i = 0; i < n2; i++)
    ans[n1 - 1][i] = s[t++];
  for(int i = n1 - 2; i >= 0; i--)
    ans[i][n2 - 1] = s[t++];
  for(int i = 0; i < n1; i++)
    for(int j = 0; j < n2; j++) {
      printf("%c", ans[i][j]);
      if(j == n2 -1)
        printf("\n");
    }
  return 0;
}
