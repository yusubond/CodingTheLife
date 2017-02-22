#include <iostream>
#include <cstdio>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
char s1[1005];
int visit[256];
int main() {
  int k;
  scanf("%d", &k);
  cin.getline(s1, 1005);
  set<char> s;
  char pre = '#';
  int count = 0;
  for(int i = 0; i < strlen(s1); i++) {
    if(visit[int(s1[i])] != 1) {
      if(s1[i] == pre) {
        count++;
      }
      if(count % k == 0) {
        s.insert(s1[i]);
        visit[int(s1[i])] = 1;
        count = 0;
      }
    }
    pre = s1[i];
  }
  sort(s.begin(), s.end());
  for(int i = 0; i < strlen(s1); i++) {
    if(s.find(s1[i]) != s.end()) {
      printf("%c", s1[i]);
      i = i + k -1;
    } else {
      printf("%c", s1[i]);
    }
  }
  return 0;
}
