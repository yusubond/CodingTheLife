#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
//希尔排序
void shellsort(vector<int> &data) {
  int i, j, gap, n = data.size();
  for(gap = n / 2; gap > 0; gap /= 2) {
    for(i = gap; i < n; i++) {
      for(j = i - gap; j >= 0 && data[j] > data[j + gap]; j -= gap)
        swap(data[j], data[j + gap]);
    }
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  shellsort(v);
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  return 0;
}
