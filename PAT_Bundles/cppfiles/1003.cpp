#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, c1, c2;
int dist[510], weight[510], e[510][510], num[510], w[510];
bool visit[510];
const int inf=99999999;
int main() {
  scanf("%d%d%d%d", &n, &m, &c1, &c2);
  for (int i = 0; i < n; i++)
    scanf("%d", &weight[i]);
  fill(e[0], e[0]+510*510, inf);
  fill(dist, dist + 510, inf);
  int a, b, c;
  for (int i = 0; i < m; i++)
  {
    scanf("%d%d%d", &a, &b, &c);
    e[a][b]=c;
    e[b][a]=c;
  }
  dist[c1]=0;
  w[c1] = weight[c1];
  num[c1]=1;
  for (int i = 0; i < n; i++)
  {
    int u = -1, minn = inf;
    for (int j = 0; j < n; j++)
    {
      if (visit[j] == false && dist[j] < minn)
      {
        u = j;
        minn = dist[j];
      }
    }
    if (u == -1) break;
    visit[u] = true;
    for (int v = 0; v < n; v++)
    {
      if(visit[v] == false && e[u][v] != inf)
      {
        if (dist[u] + e[u][v] < dist[v])
        {
          dist[v] = dist[u] + e[u][v];
          num[v] = num[u];
          w[v] = w[u] + weight[v];
        }
        else if (dist[u] + e[u][v] == dist[v])
        {
          num[v] = num[v] + num[u];
          if (w[u] + weight[v] > w[v])
            w[v] = w[u] + weight[v];
        }
      }
    }
    printf("%d %d", num[c2],w[c2]);
    return 0;
  }
}
