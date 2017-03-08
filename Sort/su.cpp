#include<cstdio>
#include<vector>
using namespace std;
vector<int> v;
//选择排序
void selectsort(vector<int> &data) {
  int i, j, least;
  for(i = 0; i < data.size() - 1; i++) {
    least = i;
    for(j = i + 1; j < data.size(); j++) {
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
