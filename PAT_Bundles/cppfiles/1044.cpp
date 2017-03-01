#include <cstdio>
#include <vector>
using namespace std;
vector<int> sum, result;
int n, m;
void Func(int i, int &j, int &tempsum) {
  int left = i, right = n;
  while(left < right) {
    int mid = (left + right) / 2;
    if(sum[mid] - sum[i - 1] >= m) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  j = right;
  tempsum = sum[j] - sum[i - 1];
}
int main() {
  scanf("%d %d", &n, &m);
  sum.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &sum[i]);
    sum[i] += sum[i - 1];
  }
  int minans = sum[n];
  for(int i = 1; i <= n; i++) {
    int j, tempsum = 0;
    Func(i, j, tempsum);
    if(tempsum > minans)
      continue;
    if(tempsum >= m) {
      if(tempsum < minans) {
        result.clear();
        minans = tempsum;
      }
      result.push_back(i);
      result.push_back(j);
    }
  }
  for(int i = 0; i < result.size(); i += 2)
    printf("%d-%d\n", result[i], result[i + 1]);
  return 0;
}
