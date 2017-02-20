#include <cstdio>
using namespace std;
int n, m, k;
const int maxn = 100010;
int fa[maxn] = {0}, count[maxn] = {0};
int findFather(int x) {
  int a = x;
  while(x != fa[x]) {
    x = fa[x];
  }
  while(a != fa[a]) {
    int z = a;
    fa[a] = x;
    a = fa[z];
  }
  return x;
}
void Union(int a, int b) {
  int faA = findFather(a);
  int faB = findFather(b);
  if(faA != faB) {
    fa[faA] = faB;
  }
}
bool exist[maxn];
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= maxn; i++)
    fa[i] = i;
  int id, temp;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &k, &id);
    exist[id] = true;
    for(int j = 0; j < k - 1; j++) {
      scanf("%d", &temp);
      Union(id, temp);
      exist[temp] = true;
    }
  }
  for(int i = 1; i <= maxn; i++) {
    if(exist[i] == true) {
      int root = findFather(i);
      count[root]++;
    }
  }
  int numTrees = 0, numBirds = 0;
  for(int i = 1; i <= maxn; i++) {
    if(exist[i] == true && count[i] != 0) {
      numTrees++;
      numBirds += count[i];
    }
  }
  printf("%d %d\n", numTrees, numBirds);
  scanf("%d", &m);
  int ida, idb;
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &ida, &idb);
    if(findFather(ida) == findFather(idb)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
