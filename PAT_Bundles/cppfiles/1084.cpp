#include <iostream>
#include <cstring>
using namespace std;
int main() {
  string a, b;
  int lena, lenb;
  cin >> a >> b;
  lena = a.length();
  lenb = b.length();
  char c[100];
  int i = 0, j = 0, t = 0;
  while(j <= lenb - 1) {
    if(b[j] != a[i]) {
      c[t++] = a[i];
      i++;
    } else {
      i++;
      j++;
    }
  }
  if(i != lena) {
    for(int k = i; k <= lena - 1; k++) {
      c[t++] = a[k];
    }
  }
  for(int k = 0; k < t; k++) {
    if(c[k] >= 'a' && c[k] <= 'z')
      c[k] = c[k] - 32;
  }
  for(int k = 0; k < t; k++) {
    for(int m = 0; m < k; m++) {
      if(c[m] == c[k])
        c[k] = '#';
    }
  }
  for(int k = 0; k < t; k++) {
    if(c[k] != '#')
      cout << c[k];
  }
  return 0;
}
