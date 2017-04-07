#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
  int n,m;
  while(cin >> n >> m) {
    double toal = n;
    double temp = n * 1.0;
    for(int i = 1; i < m; i++) {
      toal += sqrt(temp);
      temp = sqrt(temp);
    }
    printf("%.2f\n", toal);
  }
  return 0;
}
