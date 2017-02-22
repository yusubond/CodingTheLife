#include <cstdio>
using namespace std;
int num[100005];
int count[100005];
int main() {
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
    count[num[i]]++;
  }
  for(int i = 0; i < n; i++) {
    if(count[num[i]] == 1) {
      printf("%d", num[i]);
      return 0;
    }
  }
  printf("None");
  return 0;
}
