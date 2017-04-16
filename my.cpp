#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
int reset(int *i) {
  *i = *i + 2;
  return *i;
}
int main() {
  int j = 2;
  reset(&j);
  cout << j << endl;
  return 0;
}
