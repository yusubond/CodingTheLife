#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct NODE {
  int addr, key, num, next;
}node[maxn];
bool visit[maxn];
bool cmp1(NODE a, NODE b) {
  return a.num < b.num;
}
int main() {
  int start, n, count1 = 0, count2 = 0, a;
  scanf("%d %d", &start, &n);
  for(int i = 0; i < maxn; i++)
    node[i].num = 2 * maxn;   //保证有效数据均在前面的序列中
  for(int i = 0; i < n; i++) {
    scanf("%d", &a);
    scanf("%d %d", &node[a].key, &node[a].next);
    node[a].addr = a;
  }
  for(int i = start; i != -1; i = node[i].next) {
    if(visit[abs(node[i].key)] == false) {
      visit[abs(node[i].key)] = true;
      node[i].num = count1;
      count1++;
    } else {
      node[i].num = maxn + count2;
      count2++;
    }
  }
  sort(node, node + maxn, cmp1);
  int count = count1 + count2;
  for(int i = 0; i < count; i++) {
    if(i != count1 - 1 && i != count - 1)
      printf("%05d %d %05d\n", node[i].addr, node[i].key, node[i + 1].addr);
    else
      printf("%05d %d -1\n", node[i].addr , node[i].key);
  }
  return 0;
}
