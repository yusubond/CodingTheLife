## 排序算法

### #1插入排序

前段序列为有序序列，后段序列为无序序列。其思想为：将后段元素逐一插入到前段有序序列的适当位置。

最差时间复杂度：O(n^2)  
最优时间复杂度：O(n)  
平均时间复杂度：O(n^2)  
稳定性：稳定  

程序：[插入排序](insertsort.cpp)

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

### #2选择排序

前段序列为有序序列，后段序列为无序序列。其思想为：选取后段无序序列中的最值，并与无序序列的第一个值交换位置，不断地缩小无序序列长度。

最差时间复杂度：O(n^2)  
最优时间复杂度：O(n^2)  
平均时间复杂度：O(n^2)  
稳定性：不稳定  

程序：[选择排序](selectsort.cpp)

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

### #3快速排序

采用分治思想。在待排序序列中选取一个基准值，然后将大于或者小于基准值的元素分别放入两个子序列中，然后对两个子序列进行同样操作。

最差时间复杂度：O(n^2)  
平均时间复杂度：O(nlogn)  

稳定性：不稳定  

程序：[快速排序](quicksort.cpp)

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

### #4堆排序

堆排序采用的是二叉树结构，根据父节点与子节点的大小关系划分为最大堆和最小堆。虽然，其使用二叉树，但是在存储数据时，却使用数组的形式(下标i为父节点，子节点为2 * 1 + 1, 2 * i + 2)，因此处理起来也相对容易。

程序：[最大堆](maxheapsort.cpp)  
程序：[最小堆](minheapsort.cpp)

因为，每次建堆均将数据插入到数组的尾部，所以，每次 **插入新的数据** 后需要 **上调** 数据。

```c++
void MinHeapFixup(int a[], int i) {
  int j = (i - 1) / 2;
  int temp = a[i];
  while(j >= 0 && i != 0) {
    if(a[j] <= temp)
      break;
    a[i] = a[j];
    i = j;
    j = (i - 1) / 2;
  }
  a[i] = temp;
}
//建堆
void MinHeapInsert(int a[], int n, int num) {
  a[n] = num;
  MinHeapFixup(a, n);
}
```

因为，每次删除数据均是 **从顶部删除**，所以，删除后需要将尾部元素放入顶部，再进行数据 **下调**。

```c++
void MinHeapFixDown(int a[], int i, int n) {
  int j = 2 * i + 1;
  int temp = a[i];
  while(j < n) {
    if(j + 1 < n && a[j + 1] < a[j]) j++;
    if(temp <= a[j])
      break;
    a[i] = a[j];
    i = j;
    j = 2 * i + 1;
  }
  a[i] = temp;
}
```

### #5归并排序

其思想是：采用分治算法。先比较前后两个元素，形成有序序列；然后，对若干个有序序列进行排序。**递归思想**

```c++
//第一步：合并有序序列
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
  return;
}
//第二步：切分数据，形成若干个子序列
void mergesort(vector<int> &data, int first, int last) {
  if(first < last) {
    int mid = (first + last) / 2;
    mergesort(data, first, mid);
    mergesort(data, mid + 1, last);
    mergedata(data, first, mid, last);
  }
  return;
}
```

### #6桶排序，也称为计数排序

其思想是：根据待排序列的取值范围，生成可以一个包含所有元素的数组，对每个元素出现的次数(用元素值作为新数组的下标)。这样，新数组便存储了排序序列。

```c++
void bucketsort(vector<int> &data, int maxnum) {
  vector<int> temp(maxnum + 1);
  fill(temp.begin(), temp.end(), 0);
  for(int i = 0; i < data.size(); i++) {
    temp[data[i]]++;
  }
  int k = 0;
  for(int i = 0; i <= maxnum; i++) {
    while(temp[i] > 0) {
      data[k++] = i;
      temp[i]--;
    }
  }
}
```
