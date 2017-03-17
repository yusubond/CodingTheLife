#include <cstdio>
using namespace std;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  int count = 0, flag = 0;
  while(n != m) {
    for(int i = n - 1; i > 1 && flag == 0; i--) {
      if(n % i == 0 && n + i <= m && flag == 0) {
        n += i;
        count++;
        if(n == m)
          flag = 1;
        else
          flag = 0;
        break;
      }
    }
  }
  printf("%d", count);
  return 0;
}
