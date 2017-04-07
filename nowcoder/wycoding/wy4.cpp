/*
* Author: subond
* Time: 2017-3-17
* Problem：计算暗黑字符串的个数(a,b,c不存在一个长度为3的连续子串)
* 分析：1）每增加一位有三种可能，不考虑黑暗是否组成黑暗字符串的情况下，总结3f(n-1)个
* 2）考虑组成黑暗字符串时，有两种情况，第一种，最后一位的字符为前两位中的某一位，所有有2f(n-1)种情况；第二种，最后一位字符与前一位字符相同，则有f(n-2)种情况
* Answer: Passed
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
