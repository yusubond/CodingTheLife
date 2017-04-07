/*
* Author: subond
* Time: 2017-04-07
* Question: 进制均值
* 解题思路：1）计算一个数n在某进制下的各位数的和，即comput函数
*         2）统计2-(n-1)进制下的各位数和的和
*         3）最大公约数函数，即gcd函数
 */
#include <iostream>
using namespace std;
int sum[5010];
int r[5010];
int comput(int x, int y) {
  int totall = 0, m, res;
  while(x >= y) {
    m = x / y;
    res = x % y;
    totall += res;
    x = m;
  }
  totall += m;
  return totall;
}
int gcd(int x, int y) {
  while(y) {
    int res = x % y;
    x = y;
    y = res;
  }
  return x;
}
int main() {
  int n, i, j, toal;
  sum[1] = 0;
  sum[2] = 0;
  sum[3] = 2;
  r[1] = -1;
  r[2] = 0;
  r[3] = 1;
  for(i = 4; i <= 5000; i++) {
    toal = 0;
    for(j = 2; j < i; j++)
      toal += comput(i,j);
    int t = gcd(toal, i - 2);
    sum[i] = toal / t;
    r[i] = (i - 2) / t;
  }
  while(cin >> n) {
    cout << sum[n] << "/" << r[n] << endl;
  }
  return 0;
}
