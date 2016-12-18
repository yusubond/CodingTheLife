//题目：Sign in and Sign out
//大意：查找最小Sign in和最大Sing out
//类型：查找元素
//解题关键：输入的同时直接求取最值
#include <iostream>
#include <cstdio>
using namespace std;

bool cmp(int th, int tm, int ts, int h, int m, int s) {
  if(th > h) {
    return true;
  } else if (tm > m) {
    return true;
  } else if (ts > s) {
    return true;
  }
  return false;
}
int main() {
  int n;
  scanf("%d", &n);
  string unlocked, locked;
  int unlockdeh = 23, unlockedm = 59, unlockeds = 59;
  int lockedh = 0, lockedm = 0, lockeds = 0;
  for(int i = 0; i < n; i++) {
    string id;
    cin >> id;
    int hs, ms, ss, he, me, se;
    scanf("%d:%d:%d %d:%d:%d", &hs,&ms, &ss, &he, &me, &se);
    if(cmp(hs, ms, ss, unlockdeh, unlockedm, unlockeds) == false) {
      unlockdeh = hs;
      unlockedm = ms;
      unlockeds = ss;
      unlocked = id;
    }
    if(cmp(he, me, se, lockedh, lockedm, lockeds) == true) {
      lockedh = he;
      lockedm = me;
      lockeds = se;
      locked = id;
    }
  }
  cout << unlocked << " " << locked;
  return 0;
}
