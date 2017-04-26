#include <iostream>
using namespace std;
int main() {
  int a = 0x00000000;
  int f = 0x00000001;
  int b = 0x7FFFFFFF;
  int c = 0x80000000;
  int d = 0x80000001;
  int e = 0xFFFFFFFF;
  cout << a << endl;
  cout << f << endl;
  cout << b << endl;
  cout << c << endl;
  cout << d << endl;
  cout << e << endl;
  return 0;
}
