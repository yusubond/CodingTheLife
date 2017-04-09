#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  int toal = 1;
  cin >> n >> k;
  int temp = k;
  int flag = 0;
  while(temp < n) {
    if(flag == 0) {
      temp += k + 1;
      flag = 1;
    } else if(flag == 1) {
      temp += k;
      flag = 0;
    }
    toal += 1;
  }
  if(temp > n)
    toal -= 1;
  cout << toal;
  return 0;
}
