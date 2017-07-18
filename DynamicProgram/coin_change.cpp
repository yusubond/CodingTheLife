#include <iostream>
using namespace std;

int count( int S[], int m, int n ) {
  int i, j, x, y;
  int table[n+1][m];
  for (i=0; i<m; i++)
    table[0][i] = 1;
  for (i = 1; i < n+1; i++)
  {
    for (j = 0; j < m; j++)
    {
      // Count of solutions including S[j]
      x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
      // Count of solutions excluding S[j]
      y = (j >= 1)? table[i][j-1]: 0;
      // total count
      table[i][j] = x + y;
    }
  }
  for(i = 0; i <= n; i++) {
    for(j = 0; j < m; j++) {
      if(j == m-1)
        cout << table[i][j] << endl;
      else
        cout << table[i][j] << " ";
    }
  }
  return table[n][m-1];
}

int main() {
  int n, sum;
  cin >> n >> sum;
  int set[n];
  for(int i = 0; i < n; i++)
    cin >> set[i];
  for(int i = 0; i < n; i++) {
      cout << set[i] << " ";
  }
  cout << endl << sum << endl;
  cout << count(set, n, sum) << endl;
  return 0;
}
