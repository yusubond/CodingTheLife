#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
  int id, fid, mid, num, area;
  int child[10];
}data[1005];
struct node {
  int id, people;
  double num, area;
  bool flag = false;
}ans[10000];
int father[10000];
bool visit[10000];
int findfather(int x) {
  while(x != father[x])
    x = father[x];
  return x;
}
void Union(int a, int b) {
  int faA = findfather(a);
  int faB = findfather(b);
  if(faA > faB)
    father[faA] = faB;
  else if(faA < faB)
    father[faB] = faA;
}
bool cmp(node a, node b) {
  if(a.area != b.area)
    return a.area > b.area;
  else
    return a.id < b.id;
}
int main() {
  int n, k, count = 0;
  scanf("%d", &n);
  for(int i = 0; i < 10000; i++)
    father[i] = i;
  for(int i = 0; i < n; i++) {
    scanf("%d %d %d %d", &data[i].id, &data[i].fid, &data[i].mid, &k);
    visit[data[i].id] = true;
    if(data[i].fid != -1) {
      visit[data[i].fid] = true;
      Union(data[i].fid, data[i].id);
    }
    if(data[i].mid != -1) {
      visit[data[i].mid] = true;
      Union(data[i].mid, data[i].id);
    }
    for(int j = 0; j < k; j++) {
      scanf("%d", &data[i].child[j]);
      visit[data[i].child[j]] = true;
      Union(data[i].id, data[i].child[j]);
    }
    scanf("%d %d", &data[i].num, &data[i].area);
  }
  for(int i = 0; i < n; i++) {
    int id = findfather(data[i].id);
    ans[id].id = id;
    ans[id].num += data[i].num;
    ans[id].area += data[i].area;
    ans[id].flag = true;
  }
  for(int i = 0; i < 10000; i++) {
    if(visit[i])
      ans[findfather(i)].people++;
    if(ans[i].flag)
      count++;
  }
  for(int i = 0; i < 10000; i++) {
    if(ans[i].flag) {
      ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
      ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
    }
  }
  sort(ans, ans + 10000, cmp);
  printf("%d\n", count);
  for(int i = 0; i < count; i++) {
    printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
  }
  return 0;
}
