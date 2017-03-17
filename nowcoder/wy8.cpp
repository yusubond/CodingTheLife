/*
* Author: subond
* Time: 2017-3-17
* 题意：数学计算
*/

#include <cstdio>
using namespace std;
int n1, n2, n3, n4;
int main() {
  scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
  int a, b, c;
  a = (n1 + n3) / 2;
  b = (n2 + n4) / 2;
  c = n4 - b;
  if((a - b) == n1 && (b - c) == n2 && (a + b) == n3 && (b + c) == n4)
    printf("%d %d %d", a, b, c);
  else
    printf("No");
  return 0;
}
