#include <cstdio>
using namespace std;
int main() {
  int count;
  scanf("%d", &count);
  int start[55], end[55], scan[55];
  for(int i = 1; i <=54 ; i++) {
    scanf("%d", &scan[i]);
    end[i] = i;
  }
  for(int i = 0; i < count; i++) {
    for(int j = 1; j <= 54; j++) {
      start[j] = end[j];
    }
    for(int k = 1; k <= 54; k++) {
      end[scan[k]] = start[k];
    }
  }
  char c[6] = {"SHCDJ"};
  for(int i = 1; i <= 54; i++) {
    printf("%c%d", c[(end[i] - 1) / 13], (end[i] - 1) % 13 + 1);
    if(i != 54) printf(" ");
  }
  return 0;
}
