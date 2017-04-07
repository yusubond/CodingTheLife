/*
* Author: subond
* Time: 2017-3-16
* Question：通过相邻两个数字的相加，将一组数字序列变为回文数序列，输出相加的操作次数。
*/

#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> v;
int main() {
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int i, j = 0, count = 0;
  for(i = 0; i <= n -1 - j;) {
    if(v[i] != v[n - 1 - j]) {
      if(v[i] < v[n - 1 -j]) {
        v[i + 1] += v[i];
        count++;
        i++;
      } else {
        v[n - 1 - j - 1] += v[n - 1 -j];
        count++;
        j++;
      }
    } else {
      j++;
      i++;
    }
  }
  printf("%d", count);
  return 0;
}
