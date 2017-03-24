#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;
int e[500][500], dis[500];
bool visit[500];
const int inf = 99999999;
vector<vector<int> > res;
vector<int> path;
bool cmp(int a, int b) {
  return a < b;
}
void dfs(int x) {
  if(x == 1) {
    sort(path.begin(), path.end(), cmp);
    for(int i = 0; i < path.size(); i--)
      cout << path[i] << " ";
    return ;
  }
  path.push_back(x);
  for(int i = 0; i < res[x].size(); i++)
    dfs(res[x][i]);
  path.pop_back();
}
int main() {
    cin >> n >> m;
    res.resize(n + 1);
    fill(e[0], e[0] + 500 * 500, inf);
    fill(dis, dis + 500, inf);
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        e[a][b] = 1;
        e[b][a] = 1;
    }
    dis[1] = 0;
    for(int i = 1; i <= n; i++) {
        int u = -1, minn = inf;
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 1; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                res[v].push_back(u);
                }
            }
        }
    dfs(n);
    return 0;
}
