#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n;
int findall(vector<int> v, int index, int sum, int s) {
  int count = 0;
  for(int i = 0; i < v.size(); i++) {
    sum += v[i];
    s *= v[i];
    if(sum > s)
      count += 1 + findall(v, i + 1, sum, s);
    else if(v[i] == 1)
      count += findall(v, i + 1, sum, s);
    else
      break;
    sum -= v[i];
    s /= v[i];
    while(i < v.size() - 1 && v[i] == v[i+1])
      i++;
  }
  return count;
}
int main() {
  scanf("%d", &n);
  v.resize(n + 1);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  printf("%d", findall(v, 0, 0, 1));
  return 0;
}
