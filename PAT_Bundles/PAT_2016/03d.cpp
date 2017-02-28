#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 99999999;
const int maxn = 510;
int e[maxn][maxn], w[maxn][maxn];  //存储时间和长度
int dis[maxn], dispre[maxn], weight[maxn];
int mytime[maxn];
bool visit[maxn];
int minnode = inf;
vector<int> dispath, timepath, temppath, timepre[maxn];
int st, myend;
void dfsdispath(int node) {
  dispath.push_back(node);
  if(node == st)
    return ;
  dfsdispath(dispre[node]);
}
void dfstimepath(int node) {
  temppath.push_back(node);
  if(node == st) {
    if(temppath.size() < minnode) {
      timepath = temppath;
      minnode = temppath.size();
    }
    temppath.pop_back();
    return;
  }
  for(int i = 0; i < timepre[node].size(); i++) {
    dfstimepath(timepre[node][i]);
  }
  temppath.pop_back();
}
int main() {
  fill(e[0], e[0] + maxn * maxn, inf);
  fill(w[0], w[0] + maxn * maxn, inf);
  fill(dis[0], dis[0] + maxn, inf);
  fill(dispre[0], dispre[0] + maxn, inf);
  fill(weight[0], weight[0] + maxn, inf);
  int n, m, a, b, len, t, flag;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d %d %d %d", &a, &b, &flag, &len, &t);
    e[a][b] = len;
    w[a][b] = t;
    if(flag != 1) {
      e[b][a] = len;
      w[b][a] = t;
    }
  }
  scanf("%d %d", &st, &myend);
  for(int i = 0; i < n; i++)
    dispre[i] = i;
  dis[st] = 0;
  for(int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < minn) {
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
          dispre[v] = u;
          weight[v] = weight[u] + w[u][v];
        } else if(dis[u] + e[u][v] == dis[v] && weight[u] + w[u][v] < weight[v]) {
          weight[v] = weight[u] + w[u][v];
          dispre[v] = u;
        }
      }
    }
  }
  dfsdispath(myend);
  mytime[st] = 0;
  fill(visit, visit + maxn, false);
  for(int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && mytime[j] < minn) {
        u = j;
        minn = mytime[j];
      }
    }
    if(u == -1) break;
    for(int v = 0; v < n; v++) {
      if(visit[v] == false && w[u][v] != inf) {
        if(mytime[u] + w[u][v] < mytime[v]) {
          mytime[v] = mytime[u] + w[u][v];
          timepre[v].clear();
          timepre[v].push_back(u);
        } else if(mytime[u] + w[u][v] == mytime[v]) {
          timepre[v].push_back(u);
        }
      }
    }
  }
  dfstimepath(myend);
  printf("Distance = %d", dis[myend]);
  if(dispath == timepath) {
    printf("; Time = %d", mytime[myend]);
  } else {
    printf(": ");
    for(int i = dispath.size() - 1; i >= 0; i--) {
      printf("%d", dispath[i]);
      if(i != 0) printf(" -> ");
    }
    printf("\n");
    printf("Time = %d: ", mytime[myend]);
  }
  for(int i = timepath.size() - 1; i >= 0; i--) {
    printf("%d", timepath[i]);
    if(i != 0) printf(" -> ");
  }
  return 0;
}
