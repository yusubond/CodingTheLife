/*
* Author: subond
* Time: 2017-03-23
* Question: Fibonacci数列是这样定义的：F[0] = 0,F[1] = 1
* for each i ≥ 2: F[i] = F[i-1] + F[i-2]
* 因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main() {
  int n;
  cin >> n;
  if(n == 1 || n == 0) {
    cout << 0;
    return 0;
  }
  int a = 0, b = 1;
  v.push_back(a);
  v.push_back(b);
  int temp = a + b;
  while(temp < n) {
    v.push_back(temp);
    a = b;
    b = temp;
    temp = a + b;
  }
  v.push_back(temp);
  int k = 0;
  for(int i = 0; i < v.size(); i++) {
    if(n < v[i])
      k = i;
  }
  int res;
  res = (v[k] - n) < (n - v[k - 1]) ? (v[k] - n) : (n - v[k - 1]);
  cout << res;
  return 0;
}
