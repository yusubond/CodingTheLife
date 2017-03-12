#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
//数据上调，建堆使用
void MaxHeapUp(vector<int> &data, int i) {
  int j = (i - 1) / 2;
  int temp = data[i];
  while(j >= 0 && i != 0) {
    if(data[j] > temp)
      break;
    data[i] = data[j];
    i = j;
    j = (i - 1) / 2;
  }
  data[i] = temp;
}
//数据下调，删除元素使用
void MaxHeapDown(vector<int> &data, int i, int n) {
  int j = 2 * i + 1;
  int temp = data[i];
  while(j < n) {
    if(j + 1 < n && data[j + 1] > data[j]) j++;
    if(data[j] < temp)
      break;
    data[i] = data[j];
    i = j;
    j = 2 * i + 1;
  }
  data[i] = temp;
}

int main()
{
  int n;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if(i == 0)
      printf("%d", v[i]);
    else if(i == n - 1)
      printf(" %d\n", v[i]);
    else
      printf(" %d", v[i]);
    MaxHeapUp(v, i);
  }
  printf("建堆后：\n");
  for(int i = 0; i < v.size(); i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  printf("\n");
  for(int i = v.size() - 1; i >= 1; i--) {
    swap(v[0], v[i]);
    MaxHeapDown(v, 0, i);
  }
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  return 0;
}
