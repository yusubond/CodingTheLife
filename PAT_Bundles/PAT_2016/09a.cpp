#include <cstdio>
#include <set>
#include <cmath>
using namespace std;
bool isprime(int num) {
  if(num <= 1) return false;
  int k = int(sqrt(num * 1.0));
  for(int i = 2; i <= k; i++) {
    if(num % i == 0)
      return false;
  }
  return true;
}
int main() {
  int n, m, temp, rank[10000];
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    rank[temp] = i + 1;
  }
  set<int> s;
  scanf("%d", &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", &temp);
    printf("%04d: ", temp);
    if(rank[temp] == 0) {
      printf("Are you kidding?\n");
      continue;
    }
    if(s.find(temp) == s.end()) {
      s.insert(temp);
    } else {
      printf("Checked\n");
      continue;
    }
    if(rank[temp] == 1) {
      printf("Mystery Award\n");
    } else if(isprime(rank[temp])) {
      printf("Minion\n");
    } else {
      printf("Chocolate\n");
    }
  }
  return 0;
}
