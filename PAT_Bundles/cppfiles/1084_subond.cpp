#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main() {
  string a, b;
  int lena, lenb;
  cin >> a;
  cin >> b;
  lena = a.length();
  lenb = b.length();
  int flag[128] = {false};
  for(int i = 0; i < lena; i++) {
    if(a[i] >= 'a' && a[i] <= 'z') {
      a[i] = a[i] - 32;
    }
  }
  for(int i = 0; i < lenb; i++) {
    if(b[i] >= 'a' && b[i] <= 'z') {
      b[i] = b[i] - 32;
    }
    flag[b[i]] = true;
  }
  string c;
  int t = 0;
  for(int i = 0; i < lena; i++) {
    if(!flag[a[i]]) {  //未标记
      //printf("%c", a[i]);
      for(int j = 0; j < c.length(); j++) {
        if(a[i] != c[j]) {
          c[t++] = a[i];
        }
      }
    }
  }
  for(int i = 0; i < c.length(); i++) {
    printf("%c", c[i]);
  }
  return 0;
}
