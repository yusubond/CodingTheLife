#include <cstdio>
#include <iostream>
#include <set>
#include <map>
using namespace std;
bool sureNoBroken[256];
int main() {
  int k, count = 0;
  scanf("%d", &k);
  string s;
  cin >> s;
  map<char, bool> m;
  set<char> sc;
  char pre = '#';
  s = s + '#';
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == pre)
      count++;
    else {
      if(count % k != 0)
        sureNoBroken[pre] = true;
      count = 1;
    }
    if(i != s.length() - 1)
      m[s[i]] = (count % k == 0);
      pre = s[i];
  }
  for(int i = 0; i < s.length() - 1; i++) {
    if(sureNoBroken[s[i]] == true)
      m[s[i]] = false;
  }
  for(int i = 0; i < s.length() - 1; i++) {
    if(m[s[i]] && sc.find(s[i]) == sc.end()) {
      printf("%c", s[i]);
      sc.insert(s[i]);
    }
  }
  printf("\n");
  for(int i = 0; i < s.length() - 1; i++) {
    printf("%c", s[i]);
    if(m[s[i]])
      i = i + k - 1;
  }
  return 0;
}
