//类型：数组处理
//题目大意：计算电梯运行总时间
//Author: subond
//Time: 2016-12-17
#include <iostream>
using namespace std;
int main() {
  int n, sum = 0, now = 0;
  int up = 6, down = 4, stop = 5;
  cin >> n;
  while(cin >> n) {
    if(n > now) {
      sum = sum + up * (n - now);
    } else {
      sum = sum + down * (now - n);
    }
    now = n;
    sum += stop;
  }
  cout << sum;
  return 0;
}
