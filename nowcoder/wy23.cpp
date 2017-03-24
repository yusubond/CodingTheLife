/*
* Author: subond
* Time: 2017-03-24
* Question: 二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。
* 每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
* ( (x1-x2) * (x1-x2) + (y1-y2)* (y1-y2) ) 的算术平方根小易想知道最多可以放多少块蛋糕在网格盒子里。
*/

#include <iostream>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  int count = 0, len1, len2;
  if(n < m) {
    len1 = n;
    len2 = m;
  } else {
    len1 = m;
    len2 = n;
  }
  for(int i = 0; i < len1; i++) {
    if(i % 4 == 0)
      for(int j = 0; j < len2; j++)
        if(j % 4 == 0 || j % 4 == 1)
          count++;
    if(i % 4 == 1)
      for(int j = 0; j < len2; j++)
        if(j % 4 == 1 || j % 4 == 2)
          count++;
    if(i % 4 == 2)
      for(int j = 0; j < len2; j++)
        if(j % 4 == 2 || j % 4 == 3)
          count++;
    if(i % 4 == 3)
      for(int j = 0; j < len2; j++)
        if(j % 4 == 0 || j % 4 == 3)
          count++;
  }
  cout << count;
  return 0;
}
