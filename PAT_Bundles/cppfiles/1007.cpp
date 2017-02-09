//类型：求最大子序列和
//题目大意：给定一组序列，求其最大连续子序列和，并输出最大和以及这个序列的开始值和结束值。若所有元素都小于0，则认为最大值为0，并输出首尾元素。
//思路分析：
//1) 需要标志位flag，判断是否全部为零
//2) 需要两个最大（所求最大sum和临时最大temp），逻辑1：temp>sum,更新值，逻辑2：temp<0,重新计算临时最大
//Author: subond
//Time: 2016-12-18

#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int n, flag = 0, sum = -1, temp = 0, left = 0, right = 0, tempindex = 0;
  scanf("%d", &n);
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if(v[i] > 0)
      flag = 1;
    temp = temp + v[i];
    if(temp > sum) {
      sum = temp;
      left = tempindex;
      right = i;
    } else if(temp < 0) {
      temp = 0;
      tempindex = i+1;
    }
  }
  if(flag == 0)
    printf("0 %d %d", v[0], v[n-1]);
  else
    printf("%d %d %d", sum, v[left], v[right]);
  return 0;
}
