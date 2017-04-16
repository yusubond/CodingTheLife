## 迭代器

一个迭代器的范围是由一对迭代器表示，两个迭代器分别指向 **同一个容器的元素的或者尾元素的最后一个位置**。这两个迭代器统称为begin()和end()(**永远指向元素之后的位置**)。如果容器为空，则begin和end返回的是同一个迭代器，都是尾后迭代器。这种范围也称为 **左闭合区间**，其数学表示为[begin, end)。

两个迭代器begin和end构成的合法迭代器范围的要求：

+ 指向同一个容器中的元素，或者容器最后一个元素之后的位置
+ end不在begin之前

### begin和end类型

begin和end操作生成指向容器中的第一个元素和尾元素之后的位置的迭代器。另外，带r版本的返回反向迭代器，带c版本的返回const迭代器(注意：以c开头的版本是新C++标准引入的，用于支持auto)。当不需要使用写操作时，应该使用cbegin和cend。

### 迭代器运算符

```c++
//标准容器迭代器的运算符
*iter           //返回迭代器iter所指元素的引用
iter->mem       //解引用iter并获取该元素的名为men的成员
++iter          //令iter指向容器中的上一个元素
--iter          //令iter指向容器中的上一个元素
iter1 == iter2  //判断两个迭代器是否相等，即是否指向同一个元素
iter1 != iter2  //或同一个容器的尾后迭代器
```

### 迭代器的类型

迭代器的标准库类型使用iterator和const_iterator来表示迭代器的类型。其中，iterator能 **读写** 其中的元素；const_iterator只能 **读** 其中的元素。如果vector对象或string对象是一个常量，只能使用const_iterator；如果vector对象或string对象不是常量，那么既能使用iterator也能使用const_iterator。

begin和end返回的具体类型由对象是否为常量决定，如果对象是常量，begin和end返回const_iterator，如果对象不是常量，返回iterator。

解引用迭代器课获得迭代器所指的对象。`(*it).empty()`

### vector和string迭代器支持的运算

```c++
iter + n            //迭代器的新位置与原来向前移动n个元素
iter - n            //迭代器的新位置与原来向后移动n个元素
iter += n
iter -= n
<, <=, >, >=
```
