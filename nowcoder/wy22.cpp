#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int n;
int main() {
  int sum = 0, count = 0;
  long long int s = 1;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < n; i++) {
    int sum = 0;
    long long int s = 1;
    for(int j = i; j < n; j++) {
      sum += v[i];
      s *= v[i];
      if(sum > s)
        count++;
    }
  }
  printf("%d", count);
  return 0;
}
