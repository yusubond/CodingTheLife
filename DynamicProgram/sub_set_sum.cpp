#include<iostream>
#include<vector>
using namespace std;

bool SubSetSum(vector<int> data, int n, int sum) {
  if(sum == 0)
    return true;
  if(sum != 0 && n == 0)
    return false;
  if(data[n-1] > sum)
    return SubSetSum(data, n - 1, sum);
  return SubSetSum(data, n - 1, sum) || SubSetSum(data, n - 1, sum - data[n - 1]);
}

int main() {
  int n, temp, sum;
  cin >> n >> sum;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    cin >> temp;
    v[i] = temp;
  }
  if(SubSetSum(v, n, sum))
    printf("true");
  else
    printf("false");
  return 0;
}
