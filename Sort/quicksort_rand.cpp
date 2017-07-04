#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

int randpartitioin(vector<int> &data, int low, int high) {
  int n = high - low + 1;
  int pivot = rand() % n;
  int temp = data[pivot];
  while(low < high) {
    while(low < high && data[high] >= temp) high--;
    data[pivot] = data[high];
    while(low < high && data[low] <= temp) low++;
    data[high] = data[low];
    data[low] = temp;
  }
  return low;
}
int KthSmallest(vector<int> &data, int low, int high, int k) {
  if(k > 0 && k <= high - low + 1) {
    int pos = randpartitioin(data, low, high);
    if(pos - low == k - 1)
      return data[pos];
    if(pos - low > k - 1)
      return KthSmallest(data, low, pos - 1, k);
    else
      return KthSmallest(data, pos, high, k - pos + low -1);
  } else {
    return -1;
  }
}
int main()
{
  int n;
  vector<int> v;
  scanf("%d", &n);
  v.resize(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  for(int i = 0; i < n; i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  printf("\n");
  int result = KthSmallest(v, 0, 7, 5);
  printf("%d", result);
  return 0;
}
