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
      data[j + 1] = data[j];
      j--;
    }
    data[j + 1] = temp;
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  insertsort(v);
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  return 0;
}
