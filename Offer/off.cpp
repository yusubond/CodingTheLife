#include <iostream>
using namespace std;
int main() {
  int n, m;
  double p;
  cin >> n >> m >> p;
  double price[m][n];
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cin >> price[i][j];
    }
  }

  double num[n];
  double sum = 0.0;
  for(int i = 0; i < n; i++) {
    double mi = 0.0;
    for(int j = 0; j < m; j++) {
      //cout << price[j][i] << endl;
      if(price[j][i] > mi) {
        //cout << price[j][i] << endl;
        mi = price[j][i];
      }
    }
    num[i] = mi;
    sum += num[i];
  }
  sum = sum * (1 - p);
  cout << sum << endl;
  return 0;
}
