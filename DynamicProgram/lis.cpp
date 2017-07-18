#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int> data) {
  vector<int> num(data.size());
  int res = 1;;
  fill(num.begin(), num.end(), 1);
  for(int i = 1; i < data.size(); i++) {
    for(int j = 0; j < i; j++) {
      if(data[i] > data[j] && num[i] < num[j] + 1) {
        num[i] = num[j] + 1;
        if(num[i] > res)
          res = num[i];
      }
    }
  }
  return res;
}
int LIS2(vector<int> arr, int n) {
  if(n == 1)
    return 1;
  int res, end_n = 1, result;
  for(int i = 1; i < n; i++) {
    res = LIS2(arr, i);
    if(arr[i - 1] < arr[n - 1] && res + 1 > end_n)
      end_n = res + 1;
    if(end_n > result)
      result = end_n;
  }
  return result;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
    cin >> v[i];
  printf("%d\n", LIS2(v, n));
  return 0;
}
