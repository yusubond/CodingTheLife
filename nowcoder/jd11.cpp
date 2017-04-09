#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  int toal = 0;
  cin >> n >> k;
  int temp = k;
  int flag = 0;
  while(n >= temp) {
    n -= temp;
    if(flag == 1) {
      temp = k;
      flag = 0;
    } else if(flag == 0) {
      temp = k + 1;
      flag = 1;
    }
    toal++;
  }
  cout << toal;
  return 0;
}
