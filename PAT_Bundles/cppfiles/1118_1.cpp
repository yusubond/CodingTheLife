#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
bool exist[maxn] = {false};
int n, k, q;
int father[maxn];
int findfather(int x) {
  if(x == father[x]) {
    return x;
  } else {
    int f = findfather(father[x]);
    father[x] = f;
    return f;
  }
}
int main() {
  for(int i = 1; i <= maxn; i++)
    father[i] = i;  //鸟i属于树father[i]
  scanf("%d", &n);
  int count = 0, tree = 0, temp;
  for(int i = 0; i < n; i++) {
    int bf;
    scanf("%d", &k);
    for(int j = 0; j < k; j++) {
      scanf("%d", &temp);
      if(!exist[temp]) {
        count++;
        exist[temp] = true;
      }
      if(j == 0) {
        bf = findfather(temp);
      } else {
        if(findfather(temp) != bf);
          father[findfather(temp)] = bf;
      }
    }
  }
  for(int i = 1; i <= count; i++) {
    if(father[i] == i)
      tree++;
  }
  printf("%d %d\n", tree, count);
  scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if(findfather(a) == findfather(b))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
