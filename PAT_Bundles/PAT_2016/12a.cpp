#include <cstdio>
#include <set>
using namespace std;
int friendid(int num) {
  int sum = 0;
  while(num != 0) {
    sum += num % 10;
    num = num / 10;
  }
  return sum;
}
int main() {
  int n, num;
  set<int> s;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num);
    s.insert(friendid(num));
  }
  printf("%d\n", s.size());
  for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
    if(it != s.begin())
      printf(" ");
    printf("%d", *it);
  }
  return 0;
}
