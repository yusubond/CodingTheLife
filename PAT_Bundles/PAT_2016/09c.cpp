#include <cstdio>
using namespace std;
const int maxn = 10010;
int father[maxn], count[maxn];
bool visit[maxn];
int findfather(int x) {
  if(father[x] == x)
    return x;
  else
    return father[x];
}
void unionfather(int a, int b) {
  int fa = findfather(a);
  int fb = findfather(b);
  if(fa != fb)
    father[b] = fa;
}
int main() {
  int n, k, temp, id;
  for(int i = 1; i < 10010; i++)
    father[i] = i;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &k, &id);
    visit[id] = true;
    for(int j = 0; j < k - 1; j++) {
      scanf("%d", &temp);
      unionfather(id, temp);
      visit[temp] = true;
    }
  }
  for(int i = 1; i < maxn; i++) {
    if(visit[i] == true) {
      int root = findfather(i);
      count[root]++;
    }
  }
  int numtree
}
