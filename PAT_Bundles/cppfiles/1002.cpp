#include <iostream>
#include <cstdio>
using namespace std;
int main() {
  float a[1001], b[1001], c[1001];
  for (int i = 0; i < 1001; i++)
    c[i] == 0.0;
  int m, n;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int t;
    cin >> t;
    cin >> a[t];
    c[t] += a[t];
  }
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int t;
    cin >> t;
    cin >> b[t];
    c[t] += b[t];
  }
  int count = 0;
  for (int i = 0; i < 1001; i++)
  {
    if (c[i] != 0.0)
    count++;
  }
  cout << count;
  if (count != 0)
    cout << " ";
  int temp = 1001;
  for (int i=1000; i >= 0; i--)
  {
    if (c[i] != 0.0 && count > 1)
    {
      cout << i << " ";
      printf("%.1f", c[i]);
      count--;
      temp = i;
    }
  }
  for (int i = temp - 1; i >= 0; i--)
  {
    if (c[i] != 0.0)
    {
      cout << i << " ";
      printf("%.1f", c[i]);
    }
  }
  return 0;
}
