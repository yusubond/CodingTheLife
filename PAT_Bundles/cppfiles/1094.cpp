#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int book[100];
vector<int> v[100];
int maxdepth = -1;
void dfs(int index, int depth) {
  //book[depth]++;    //这样也可以，当前结点自加
  if(v[index].size() == 0) {
    maxdepth = max(depth, maxdepth);
    return;
  }
  book[depth + 1] += v[index].size();  //将该结点的子节点加入下一层数据中
  for(int i = 0; i < v[index].size(); i++) {
    dfs(v[index][i], depth + 1);
  }
}
int main() {
  int n, m, node, k, c;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &node, &k);
    for(int j = 0; j < k; j++) {
      scanf("%d", &c);
      v[node].push_back(c);
    }
  }
  dfs(1,1);
  book[1] = 1;
  int maxnum = 0, maxlevel = -1;
  for(int j = 1; j <= maxdepth; j++) {
    if(book[j] > maxnum) {
      maxnum = book[j];
      maxlevel = j;
    }
  }
  printf("%d %d", maxnum, maxlevel);
  return 0;
}
