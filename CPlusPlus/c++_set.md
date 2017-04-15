## set常用用法

1。 set集合容器可以保证元素的唯一性，实现了红黑树的平衡二叉检索树的数据结构。插入元素时，可以自动调整二叉树的排列，把元素放到适当的位置上，以保证每个子树根节点键值大于左子树所有节点的键值，小于右子树所有节点的键值；并且保证根节点左子树的高度与右子树高度相等。

2。

`#include<set>`

1）声明：`set<int> s;`

2)元素插入：`s.insert(num);`

3)中序遍历，即将元素值从小到大输出

```
set<int>::iterator it;
for(it = s.begin(); it != s.end(); it++) {
  if(it != begin())
    printf(" ");
  printf(" %d", *it);
}
```

4)删除元素：

```c++
set<int> s;
s.erase(2);  //删除键值为2的元素
s.clear();   //清空所有元素
```

5）元素检索find():若找到，则返回键值迭代器的位置，否则，返回 **最后一个元素后面的位置**

```c++
set<int> s;
set<int>::iterator it;
it = s.find(5);
if(it != s.end()) //找到
  printf("%d", *it);
```
