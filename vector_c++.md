## vector用法

标准库类型vector表示对象的集合，其中所有对象的类型都相同。集合中的每一个对象都有一个与之对应的索引，索引用于访问对象。vector也称为“容器”。

头文件：

`#include<vector>`

1)初始化

```
vector<T> v;  //T为元素的类型
vector<t> v1(n)  //n个重复执行初始化
vector<T> v2(n, value);  //n个重复元素，每个值为value
vector<int> v;
vector<int> v1(5);
vector<int> v2(10, -1);
```

2)添加元素push_back()

```c++
vector<int> v;
for(int i = 0; i < 10; i++)
  v.push_back(i);
//当知道v的大小时，可以直接用索引复制
vector<int> v2(5);
for(int i = 0; i < 5; i++)
  v[i] = i * i;
```

3）其他操作

```c++
v.empty()  //若不含任何元素，返回真，否则返回假
v.size()   //元素个数，对象的下标从0开始
v.resize(number) //改变v的大小
v.begin()
v.end()
```

4)排序

```c++
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
sort(v.begin(), v.end(),cmp);
```
