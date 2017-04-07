/*
* Author: subond
* Time: 2017-3.17
* 题意：给定一个数n,求k1,k2,使其满足 n = 6 * k1 + 8 * k2;
*/
#include <cstdio>
#include <vector>
using namespace std;
int n;
vector<int> s6;
vector<int> s8;
int main() {
  scanf("%d", &n);
  int k = 0;
  while(k * 6 <= n) {
    s6.push_back(k * 6);
    k++;
  }
  k = 0;
  while(k * 8 <= n) {
    s8.push_back(k * 8);
    k++;
  }
  int count = -1;
  int flag = 0;
  if(n >= 8) {
    for(int i = s8.size() - 1; i >= 0 && flag == 0; i--) {
      for(int j = 0; j < s6.size() && flag == 0; j++) {
        if((s8[i] + s6[j]) == n) {
          count = i + j;
          flag = 1;
        }
      }
    }
  } else if(n >= 6) {
    for(int i = s6.size() - 1; i >= 0 && flag == 0; i--) {
      for(int j = 0; j < s8.size() && flag == 0; j++) {
        if((s6[i] + s8[j]) == n) {
          count = i + j;
          flag = 1;
        }
      }
    }
  }
  printf("%d", count);
  return 0;
}
