## map用法

c++中map容器提供一个键值对容器，允许一对一的关系。而mulitmap可以允许一个键对应多个值。

### 1. 头文件
```c++
#include <map>
```

### 2. 定义

map的定义类似vector容器，需要制定键值的类型。

```c++
map<string, int> m;
```

### 3. 插入数据

```c++
m["a"] = 1;
m.insert(map<string, int>::value_type("b", 2));
m.insert(pair<string, int>("c", 3));
m.insert(make_pair<string, int>("d", 4));
```

### 4. 查找数据和修改数据

```c++
int myvalue = m["a"];
//使用迭代器
m::iterator myit;
myit.find("b");
int myvalue = myit->second;
myit->second = 5;
//注意，键本身不能修改，只可以删除
```

### 5. 删除数据

```c++
m.erase("b");
```

### 6. 迭代数据

```c++
for(map<string, int>::iterator it = m.begin(); it != m.end(); it++) {
  printf("%s %d", it->first.c_str(), it->second);
}
```

### 7. 其他函数

m.size();  //返回元素个数
m.empty(); //判断是否为ks
m.clear(); //清空元素
