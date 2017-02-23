#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 99999999;
int e[210][210];
int dis[210];
bool visit[210] = {false};
struct node {
  char name[5];
  int id;
  int happy;
};
vector<node> v;
vector<int> path, temppath;
int getid(char name[5]) {
  for(int i = 0; i < v.size(); i++) {
    if(strcmp(name, v[i].name) == 0)
      return v[i].id;
  }
  return -1;
}
void dfs(int node) {
  if(node == end) {
    temppath.push_back(node);
    int happy, avghappy;
    for(int i = temppath.size() - 1; i >= 0; i--) {
      happy += v[temppath[i]].happy;
    }
  }
}
int main() {
  fill(e[0], e[0] + 210 * 210, inf);
  fill(dis[0], dis[0] + 210, inf);
  int n, k;
  char start[5];
  scanf("%d %d %s", &n, &k, start);
  v.resize(n);
  v[0].name = start;
  v[0].id = 0;
  v[0].happy = 0;
  for(int i = 1; i <= n - 1; i++) {
    scanf("%s %d", &v[i].name, &v[i].happy);
    v[i].id = i;
  }
  char endname[5] = {'ROM'};
  int end = getid(endname);
  char tname1[5], tname2[5];
  int cost;
  for(int i = 1; i <= k; i++) {
    int id1, id2;
    scanf("%s %s %d", tname1, tname2, &cost);
    id1 = getid(tname1);
    id2 = getid(tname2);
    e[id1][id2] = cost;
    e[id2][id2] = cost;
  }
  dis[0] = 0;
  for(int i = 0; i < n; i++) {
    int u = -1, minn;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < inf) {
        u = j;
        minn = dis[j];
      }
    }
    if(u == -1) break;
    visit[u] = true;
    for(int v = 0; v < n; v++) {
      if(visit[v] == false && e[u][v] != inf) {
        if(dis[u] + e[u][v] < dis[v]) {
          dis[v] = dis[u] + e[u][v];
          pre[v].clear();
          pre[v].push_back(u);
        } else if(dis[u] + e[u][v] == dis[v]) {
          pre[v].push_back(u);
        }
      }
    }
  }
  dfs();
}
