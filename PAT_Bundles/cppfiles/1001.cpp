#include <iostream>
using namespace std;
int main() {
  int a, b, result, t = 0;
  cin >> a >> b;
  result = a + b;
  if(result == 0){
    cout << 0;
    return 0;
  }
  if(result < 0) {
    cout << "-";
    result = result * (-1);
  }
  int s[7];
  while(result) {
    s[t++] = result % 10;
    result /= 10;
  }
  int count = t;
  for(int i = t - 1; i >= 0; i--) {
    cout << s[i];
    count--;
    if(count % 3 == 0 && count != 0)
      cout << ",";
  }
  return 0;
}
