/*
* Author: subond
* Time: 2017-3-17
* 题意：计算暗黑字符串的个数
*/

#include <cstdio>
using namespace std;
long long int total(int num) {
  if(num == 0)
    return 0;
  else if(num == 1)
    return 3;
  else if(num == 2)
    return 9;
  else
    return  2 * total(num - 1) + total(num - 2);

}
int main() {
  int num;
  while(scanf("%d", &num) == 1)
    printf("%lld\n", total(num));
  return 0;
}
