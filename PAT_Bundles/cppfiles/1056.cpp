#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
  int weight;
  int index;   //比赛标号
  int rank;
  int index0;  //原始顺序标号，用于恢复原始顺序 sort
};
bool cmp(node a, node b) {
  return a.index0 < b.index0;
}
int main() {
  int n, g, num;
  scanf("%d %d", &n, &g);
  vector<int> v(n);
  vector<node> w(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num);
    w[i].weight = v[num];
    w[i].index = i;
    w[i].index0 = num;
  }
  queue<node> q;
  for(int i = 0; i < n; i++)
    q.push(w[i]);
  while(!q.empty()) {
    int size = q.size();
    if(size == 1) {
      node temp = q.front();
      w[temp.index].rank = 1;
      break;
    }
    int group = size / g;
    if(size % g != 0)
      group += 1;

    node maxnode;
    int maxn = -1, count = 0;
    for(int i = 0; i < size; i++) {
      node temp = q.front();
      w[temp.index].rank = group + 1;
      q.pop();
      count++;
      if(temp.weight > maxn) {
        maxn = temp.weight;
        maxnode = temp;
      }
      if(count == g || i == size - 1) {
        count = 0;
        maxn = -1;
        q.push(maxnode);
      }
    }
  }
  sort(w.begin(), w.end(), cmp);
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", w[i].rank);
    else
      printf(" %d", w[i].rank);
  }
  return 0;
}
