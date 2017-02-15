#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n;
  long long p;
  cin >> n >> p;
  if(n == 0) {
    cout << 0;
    return 0;
  }
  long long int *a = new long long int [n];
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);   //默认升序排列
  int result = 1;
  int temp = 1;
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + result; j <= n - 1; j++) {  //使用i + result可以提供运行效率，避免运行超时
      if(a[i] * p >= a[j]) {
        temp = j - i + 1;
        if(temp > result)
          result = temp;
      } else {
        break;
      }
    }
  }
  cout << result;
  return 0;
}
