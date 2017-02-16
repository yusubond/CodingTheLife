## 需要注意的地方

### 1)数据存储

19 5  
scanf("%d %d", &a, &b);

08:02:04  
scanf("%d:%d:%d", &HH, &MM, &SS);

### 2)常用的排序算法

`#include <algorithm>`

sort函数：对指定区间的所有元素进行排序。结合vector使用，例如sort(vector.begin(), vector.end(), cmp)

sort(begin, end)
sort(begin, end, cmp)

### 3)vector的用法

`#include <vector>`

### 4)图的遍历，比较 **前序和中序转后序** 与 **后序和中序转前序** 的区别

c++代码：已知前序和中序，转为后序

```c++
#include <vector>
vector<int> pre, in, post;
void pre2post(int root, int start, int end) {
  //root表示子树的根节点在在前序pre中的下标
  //start和end表示子树的最左边和最右边在中序in中的下标
  if(start > end) return;
  int i = start;
  //在中序in中寻找根节点，其下标标记为i
  while(i < end && in[i] != pre[root])
    i++;
  //i为根节点在中序in中的下标，则将中序分为两段
  //处理前半段，即左子树：新根为 root+1, 起点 start, 终点 i-1
  pre2post(root + 1, start, i - 1);  //前半段的长度 i-start
  //处理后半段，即右子树：新根为 root + 1 + （i - start）位移，起点 i+1, 终点 end
  pre2post(root + 1 + i - start, i + 1, end);
  //压入根节点
  post.push_back(pre[root]);
}
  //应用
  pre2post(0, 0, n - 1);
  //顺序输出post，即是后序序列
```

c++代码：已知后序和中序，转为前序

```c++
#include <vector>
vector<int> pre, in, post;
void post2pre(int root, int start, int end) {
  //root表示子树根节点在后序post中的下标
  //start和end表示子树的最左边和最右边在中序in中的下标
  if(start > end) return ;
  int i = start;
  while(i < end && in[i] != post[root]) i++;
  //先压入根节点
  pre.push_back(post[root]);
  //处理前半段，即左子树：新根为 root-1-(end-i)，起点为 start，终点为 i-1
  post2pre(root - 1 - end + i, start, i - 1);
  //处理后半段，即右子树：新根为 root-1，起点为 i+1，终点为 end
  post2pre(root - 1, i + 1, end);
}
  //应用
  post2pre(n - 1, 0, n - 1);
  //顺序输出pre，即是前序序列
```

### 5)字符串长度

对于字符串长度，使用其成员函数输出。需要包含头文件`#include <cstring>`。

```c++
#include <iostream>
#include <cstring>
using namespace std;
string a;
cin >> a;
int lena = a.length();
```
