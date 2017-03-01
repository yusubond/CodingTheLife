#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct node {
  int id;
  int layer;
};
int n, l, m, k;
vector<vector<int> > v;
int dfs(node x) {
  bool visit[1010] = {false};
  queue<node> q;
  q.push(x);
  visit[x.id] = true;
  int count = 0;
  while(!q.empty()) {
    node top = q.front();
    q.pop();
    int topid = top.id;
    for(int i = 0; i < v[topid].size(); i++) {
      int nextid = v[topid][i];
      if(visit[nextid] == false && top.layer < l) {
        node next;
        next.id = nextid;
        next.layer = top.layer + 1;
        q.push(next);
        visit[nextid] = true;
        count++;
      }
    }
  }
  return count;
}
int main() {
  scanf("%d %d", &n, &l);
  v.resize(n + 1);
  int temp, k;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &k);
    for(int j = 0; j < k; j++) {
      scanf("%d", &temp);
      v[temp].push_back(i);
    }
  }
  int m, t;
  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", &t);
    node tnode;
    tnode.id = t;
    tnode.layer = 0;
    int ans = dfs(tnode);
    printf("%d\n", ans);
  }
  return 0;
}
