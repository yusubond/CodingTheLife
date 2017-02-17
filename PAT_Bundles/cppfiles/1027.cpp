#include <cstdio>
using namespace std;
void print(int num) {
  if(num == 10)
    printf("A");
  if(num == 11)
    printf("B");
  if(num == 12)
    printf("C");
  if(num < 10)
    printf("%d", num);
}
int num13(int number) {
  int a, b;
  a = number / 13;
  b = number - a * 13;
  print(a);
  print(b);
}
int main() {
  printf("#");
  int f;
  for(int i = 0; i < 3; i++) {
    scanf("%d", &f);
    num13(f);
  }
  return 0;
}
