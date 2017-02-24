#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct node {
  int addr, num, next;
};
const int inf = 99999999;
vector<node> v[100010];
vector<node> last;
bool visit[10010];
void dfs(int x, int depth) {
  if(depth == 0)
    v[x].next = -1
  if(v[x].next == -1 || depth == 0) {
    return;
  } else {
    if(visit[abs(v[x]) == false) {
      visit[abs(v[x])] = true;
      printf("%05d %d %05d\n", v[node].addr, v[node].num, v[node].next);
      dfs(v[x].next, n - 1);
    } else {
      last.push_back(v[node]);
      dfs(v[v[x].next].next, n - 2);
    }
  }

}
int main() {
  fill(visit, visit + 10010, false);
  int start, n;
  scanf("%d %d", &start, &n);
  int tempaddr, tempnum, tempnext;
  for(int i = 0; i < n; i++) {
    scanf("%d %d %d", &tempaddr, &tempnum, &tempnext);
    v[tempaddr].addr = addr;
    v[tempaddr] = tempnum;
    v[tempaddr].next = tempnext;
  }
  visit[abs(v[start])] = true;
  dfs(start, n);
  for(int i = 0; i < last.size(); i++) {
    printf("%05d %d %05d\n", last[i].addr, last[i].num, last[i].next);
  }
  return 0;
}
