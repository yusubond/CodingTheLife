#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int countp = 0, countt = 0;
  int len = s.length(), result = 0;
  for(int i = 0; i < len; i++)
    if(s[i] == 'T')
      countt++;
  for(int i = 0; i < len; i++) {
    if(s[i] == 'P')
      countp++;
    if(s[i] == 'T')
      countt--;
    if(s[i] == 'A') {
      result = (result + (countp * countt) % 1000000007) % 1000000007;
    }
  }
  printf("%d", result);
  return 0;
}
