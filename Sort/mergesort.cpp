#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
void mergedata(vector<int> &data, int first, int mid, int last) {
  int i = first, j = mid + 1;
  vector<int> temp;
  while(i <= mid && j <= last) {
    if(data[i] <= data[j])
      temp.push_back(data[i++]);
    else
      temp.push_back(data[j++]);
  }
  while(i <= mid)
    temp.push_back(data[i++]);
  while(j <= last)
    temp.push_back(data[j++]);
  for(int k = 0; k < temp.size(); k++)
    data[first + k] = temp[k];
}
void mergesort(vector<int> &data, int first, int last) {
  if(first < last) {
    int mid = (first + last) / 2;
    mergesort(data, first, mid);
    mergesort(data, mid + 1, last);
    mergedata(data, first, mid, last);
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  mergesort(v, 0, v.size() - 1);
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  return 0;
}
