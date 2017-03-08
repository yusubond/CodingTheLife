#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
//插入排序
void insertsort(vector<int> &data) {
  for(int i = 1; i < data.size(); i++) {
    int j = i - 1;
    int temp = data[i];
    while(j >= 0 && data[j] > temp) {
      data[ j+ 1] = data[j];
      j--;
    }
    data[j + 1] = temp;
  }
}
//选择排序
void selectsort(vector<int> &data) {
  int i, j, least;
  for(i = 0; i <data.size() - 1; i++) {
    for(j = i + 1, least = i, j < n; j++) {
      if(data[j] < data[least])
        least = j;
    }
    swap(data[least], data[i]);
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  selectsort(v);
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  return 0;
}
