#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
//数据下沉调整
void MinHeapFixDown(vector<int> &data, int i, int n) {
  int j, temp;
  temp = data[i];
  j = 2 * i + 1;
  while(j < n) {
    if(j + 1 < n && data[j + 1] < data[j]) j++;
    if(temp <= data[j])
      break;
    data[i] = data[j];
    i = j;
    j = 2 * i + 1;
  }
  data[i] = temp;
}
//堆排序
void MakeMinHeap(vector<int> &data) {
  for(int i = data.size() / 2 - 1; i >= 0; i--)
    MinHeapFixDown(data, i, data.size());
}
//删除数据
int main()
{
  int n;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  MakeMinHeap(v);
  for(int i = v.size() - 1; i >= 1; i--) {
    swap(v[i], v[0]);
    MinHeapFixDown(v, 0, i);
  }
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  return 0;
}
