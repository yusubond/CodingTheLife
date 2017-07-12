#include <iostream>
#include <algorithm>
using namespace std;

int find(int a, int b, int c) {
  int result;
  result = a > b ? a : b;
  result = result > c ? result : c;
  return result;
}

// 找出矩阵中的严格递增的节点最大数
int FindMaxPath(int data[][4], int n);
int FindMaxPath(int data[][4], int n) {
  int num[n][n];
  fill(num[0], num[0] + n * n, 1);
  int maxnum = -1, temp = -1;
  int tempnum = 0;
  while(1) {
    for(int i = 0; i < n; i++) {
      // 只进行前后比较即可
      if(i == n-1) {
        for(int j = 0; j < n - 1; j++) {
          if(data[i][j] > data[i][j+1] && num[i][j] <= num[i][j+1])
            num[i][j] = num[i][j+1] + 1;
          if(data[i][j] < data[i][j+1] && num[i][j] >= num[i][j+1])
            num[i][j+1] = num[i][j] + 1;
          tempnum = num[i][j] > num[i][j+1] ? num[i][j] : num[i][j+1];
          temp = tempnum >= temp ? tempnum : temp;
        }
      } else {
      // 进行前后和上下比较
      for(int j = 0; j < n; j++) {
        if(j == n-1) {
          if(data[i][j] > data[i+1][j] && num[i][j] <= num[i+1][j])
            num[i][j] = num[i+1][j] + 1;
          if(data[i][j] < data[i+1][j] && num[i][j] >= num[i+1][j])
            num[i+1][j] = num[i][j] + 1;
          tempnum = num[i][j] > num[i+1][j] ? num[i][j] : num[i+1][j];
          temp = tempnum >= temp ? tempnum : temp;
        } else {
          if(data[i][j] > data[i+1][j] && num[i][j] <= num[i+1][j])
            num[i][j] = num[i+1][j] + 1;
          if(data[i][j] < data[i+1][j] && num[i][j] >= num[i+1][j])
            num[i+1][j] = num[i][j] + 1;
          if(data[i][j] > data[i][j+1] && num[i][j] <= num[i][j+1])
            num[i][j] = num[i][j+1] + 1;
          if(data[i][j] < data[i][j+1] && num[i][j] >= num[i][j+1])
            num[i][j+1] = num[i][j] + 1;
          tempnum = find(num[i][j], num[i+1][j], num[i][j+1]);
          temp = tempnum >= temp ? tempnum : temp;
        }
      }
    }
  }
  if(temp == maxnum) {
    return maxnum;
    break;
  }
  if(temp > maxnum)
    maxnum = temp;
}
}

int main() {
  int n, temp;
  cin >> n;
  int data[4][4];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> temp;
      data[i][j] = temp;
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(j == n-1)
        printf("%d\n", data[i][j]);
      else
        printf("%d ", data[i][j]);
    }
  }
  printf("%d", FindMaxPath(data, n));
  return 0;
}
