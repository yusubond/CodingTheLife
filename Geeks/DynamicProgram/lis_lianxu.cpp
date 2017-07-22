#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lis(vector<int> data) {
  int result = -1, temp = 1;
  for(int i = 1; i < data.size(); i++) {
    if(data[i-1] < data[i]) {
      temp++;
      if(temp > result)
        result = temp;
    } else {
      temp = 1;
    }
  }
  return result;
}

int main() {
  int n, temp;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++) {
    cin >> temp;
    v[i] = temp;
  }
  for(int i = 0; i < v.size(); i++) {
    if(i == v.size()-1)
      printf("%d\n", v[i]);
    else
      printf("%d ", v[i]);
  }
  printf("%d\n", lis(v));
  return 0;
}
