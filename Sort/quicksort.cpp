#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
//快速排序
int division(vector<int> &data, int low, int high) {
  int temp = data[low];
  while(low < high) {
    while(low < high && data[high] >= temp) high--;
    data[low] = data[high];
    while(low < high && data[low] <= temp) low++;
    data[high] = data[low];
    data[low] = temp;
  }
  return low;
}
void quicksort(vector<int> &data, int low, int high) {
  if(low < high) {
    int i = division(data, low, high);
    quicksort(data, low, i - 1);
    quicksort(data, i + 1, high);
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  quicksort(v, 0, v.size() - 1);
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  return 0;
}
