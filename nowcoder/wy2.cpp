/*
* Author: subond
* Time: 2017-3-16
* 题意：给定一个半径的平方，求圆上坐标为整数的点的个数
*
*/
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int n;
set<int> s;
vector<int> result;
int main() {
  scanf("%d", &n);
  int num = n / 2;
  int i = 0;
  while(i * i <= n) {
    s.insert(i * i);
    i++;
  }
  for(int j = 0; j * j <= num; j++) {
    if(s.find(n - j * j) != s.end()) {
      result.push_back(j);
    }
  }
  int count = 0;
  if(result.size() == 0) {
    count = 0;
  } else {
    for(int i = 0; i < result.size(); i++) {
      if(result[i] == 0 || result[i] * result[i] * 2 == n)
        count += 4;
      else
        count += 8;
    }
  }
  printf("%d", count);
  return 0;
}
