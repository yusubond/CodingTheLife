#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];

  const int m = ceil(n * 0.6) + 1E-5;
  vector<vector<double> > dp(n, vector<double>(n + 1, 0));
  dp[0][1] = double(p[0]) / 100.0;
  dp[0][0] = 1 - double(p[0]) / 100.0;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = (1 - p[i] / 100.0) * dp[i - 1][0];
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = p[i] / 100.0 * dp[i - 1][j - 1] + (100 - p[i]) / 100.0 * dp[i - 1][j];
    }
  }
  double sum = 0;
  for(int i = m; i <= n; ++i) sum += dp[n - 1][i];
  cout << setprecision(5) << fixed  << sum << endl;
}
