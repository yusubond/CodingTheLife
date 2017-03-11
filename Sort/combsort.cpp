#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
void combsort(vector<int> &data, int step) {
  int i, j;
  while(step = int(step / 1.3) > 1) {
    for(i = data.size() - 1; i >= step; i--) {
      j = i - step;
      if(data[j] > data[i])
        swap(data[j], data[i]);
    }
  }
}
int main()
{
  int n, step = 3;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  combsort(v, v.size());
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  return 0;
}
