/*
* Author: subond
* Time: 2017-03-16
* Problem: 求最大的奇数约数的和f(n) + f(n-1) + ... + f(1)
 */
#include <iostream>
using namespace std;
long long int getnum(long long int x) {
  if(x % 2 == 1)
    return x;
  else {
    while(x % 2 == 0 && x >= 1) {
      x /= 2;
    }
    return x;
  }
}
int main() {
  long long int n, num = 0;
  cin >> n;
  for(int i = n; i >= 1; i--) {
    num += getnum(i);
  }
  cout << num;
  return 0;
}
