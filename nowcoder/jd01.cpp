/*
* Author: subond
* Time: 2017-04-07
* Question: 合并集合
 */
#include <cstdio>
#include <set>
using namespace std;
int main() {
  int n, m, temp;
  set<int> s;
  while(scanf("%d %d", &n, &m) != EOF) {
    for(int i = 0; i < n; i++) {
      scanf("%d", &temp);
      s.insert(temp);
    }
    for(int i = 0; i < m; i++) {
      scanf("%d", &temp);
      s.insert(temp);
    }
    set<int>::iterator it;
    for(it = s.begin(); it != s.end(); it++) {
      if(it != s.begin())
        printf(" ");
      printf("%d", *it);
    }
    printf("\n");
    s.clear();
  }
}
