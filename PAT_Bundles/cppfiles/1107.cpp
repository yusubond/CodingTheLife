#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> father, book;
int cmp(int a, int b) {
  return a > b;
}
int findfather(int x) {
  while(x != father[x])
    x = father[x];
  return x;
}
void myunion(int a, int b) {
  int faA = findfather(a);
  int faB = findfather(b);
  if(faA != faB)
    father[faA] = faB;
}
int main() {
  int n, k, t, count = 0;
  int course[1001] = {0};
  scanf("%d", &n);
  father.resize(n + 1);
  book.resize(n + 1);
  for(int i = 1; i <= n; i++)
    father[i] = i;
  for(int i = 1; i <= n; i++) {
    scanf("%d:", &k);
    for(int j = 0; j < k; j++) {
      scanf("%d", &t);
      if(course[t]  == 0)
        course[t] = i;
      myunion(i, findfather(course[t]));
    }
  }
  for(int i = 1; i <= n; i++)
    book[findfather(i)]++;
  for(int i = 1; i <= n; i++) {
    if(book[i] != 0)
      count++;
  }
  printf("%d\n", count);
  sort(book.begin(), book.end(), cmp);
  for(int i = 0; i < count; i++) {
    printf("%d", book[i]);
    if(i != count - 1) printf(" ");
  }
  return 0;
}
