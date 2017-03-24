#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> vx, vy;
int n;
int main() {
  cin >> n;
  vx.resize(n);
  vy.resize(n);
  int temp, minsum, res;
  for(int i = 0; i < n; i++)
    cin >> vx[i];
  for(int i = 0; i < n; i++) {
    cin >> vy[i];
    if(i == 0)
      minsum = pow(vx[0] - 1, 2) + pow(vy[0] - 1, 2);
    temp = pow(vx[i] - 1, 2) + pow(vy[i] - 1, 2);
    if(temp < minsum) {
      minsum = temp;
      res = i;
    } else {
      res = 0;
    }
  }
  int count;
  count = vx[res] + vy[res] - 2;
  cout << count;
  return 0;
}
