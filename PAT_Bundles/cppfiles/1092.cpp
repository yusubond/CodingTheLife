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
  int count = 0;
  for(int i = 0; i < lenb; i++) {
    for(int j = 0; j < lena; j++) {
      if(b[i] == a[j]) {
        a[j] = '#';
        count++;
        break;
      }
    }
  }
  int result = lenb - count;
  if(result == 0) {
    printf("Yes %d", lena - lenb);
  } else {
    printf("No %d", result);
  }
  return 0;
}
