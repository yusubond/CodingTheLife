#include <ctsdio>
#include <vector>
using namespace std;
vector<int> v;
int n;
int main() {
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  int count;
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++)
    printf("%d", v[i]);
  return 0;
}
