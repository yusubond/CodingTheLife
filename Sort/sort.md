## sort

### 插入排序：前段序列为有序序列，后段序列为无序序列。其思想为：将后段元素逐一插入到前段有序序列的适当位置。

最差时间复杂度：O(n^2)  
最优时间复杂度：O(n)  
平均时间复杂度：O(n^2)  
稳定性：稳定  

```c++
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
```

### 选择排序：前段序列为有序序列，后段序列为无序序列。其思想为：选取后段无序序列中的最值，并与无序序列的第一个值交换位置，不断地缩小无序序列长度。

最差时间复杂度：O(n^2)  
最优时间复杂度：O(n^2)  
平均时间复杂度：O(n^2)  
稳定性：不稳定  

```c++
void selectsort(vector<int> &data) {
  int i, j, least;
  for(i = 0; i < data.size() - 1; i++) {
    least = i;
    for(j = i + 1; j < data.size(); j++) {
      if(data[j] < data[least])
        least = j;
    }
    swap(data[i], data[least]);
  }
}
```

### 快速排序：采用分治思想。在待排序序列中选取一个基准值，然后将大于或者小于基准值的元素分别放入两个子序列中，然后对两个子序列进行同样操作。

最差时间复杂度：O(n^2)  
平均时间复杂度：O(nlogn)  

稳定性：不稳定  

```c++
int division(vector<int> &data, int low, int high) {
  int base = data[low];
  while(low < high) {
    while(low < high && data[high] >= base) high--;
    data[low] = data[high];
    while(low < high && data[low] <= base) low++;
    data[high] = data[low];
    data[low] = base;
  }
  return low;
}
void quicksort(vector<int> &data, int low, int high) {
  if(low < high) {
    int mid = division(data, low, high);
    quicksort(data, low, i - 1);
    quicksort(data, i + 1, high);
  }
}
```
