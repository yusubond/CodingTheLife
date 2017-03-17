#include <iostream>
using namespace std;
long long int getnum(long long int x) {
  if(x % 2 == 1)
    return x;
  else {
    while(x % 2 == 0 && x >= 1) {
      x /= 2;
    }
    return x;
  }
}
int main() {
  long long int n, num = 0;
  cin >> n;
  for(int i = n; i >= 1; i--) {
    num += getnum(i);
  }
  cout << num;
  return 0;
}
