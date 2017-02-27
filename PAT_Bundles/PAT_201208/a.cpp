#include <cstdio>
#include <algorithm>
using namespace std;
int num[100010];
int visit[10010];
int n;
int main() {
  //fill(visit, visit + 1010, 0);
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
    visit[num[i]]++;
  }
  for(int i = 0; i < n; i++) {
    if(visit[num[i]] == 1) {
      printf("%d", num[i]);
      return 0;
    }
  }
  printf("None");
  return 0;
}
