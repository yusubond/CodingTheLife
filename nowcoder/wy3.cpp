#include <cstdio>
using namespace std;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  int count = 0;
  while(n != m) {
    for(int i = n - 1; i > 1; i--) {
      if(n % i == 0 && n + i <= m) {
        n += i;
        count++;
        break;
      }
    }
  }
  printf("%d", count);
  return 0;
}
