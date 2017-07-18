#include <iostream>
#include <algorithm>
using namespace std;
// 找出3*3矩阵中，给定起点的连续序列的最大长度
// 3*3的矩阵中存有随机存取26个英文字母

int FindLongestPath(char c[3][3], char x) {
  int num[3][3], temp, sum;
  fill(num[0], num[0] + 3 * 3, 1);
  while(1) {
    for(int i = 0; i < 3; i++) {
      
    }
  }
}

int main() {
  char c[3][3], temp;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cin >> temp;
      c[i][j] = temp;
    }
  }
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      if(j == 2)
        printf("%c\n", c[i][j]);
      else
        printf("%c ", c[i][j]);
    }
  }
  return 0;
}
