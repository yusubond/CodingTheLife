## 知识点总结

### review

1094,1021,1020,1019,1018,1017,1014,1016(账单，有效数据),1015,1013,1011,1009,

### 1)图论-连通分量

1）采用邻接矩阵的形式进行存储，然后进行DFS。

```c++
int v[100][100];  //边的情况
bool visit[100];  //是否遍历过
void dfs(int x) {
  visit[x] = true;
  for(int i = 1; i <= n; i++) {
    if(visit[i] == false && v[x][i] == 1)
      dfs(i);
  }
}
int count = 0;
for(int i = 1; i <= n; i++) {
  if(visit[i] == false) {
    dfs(i);
    count++;
  }
}
```

### 2)常用的排序算法

`#include <algorithm>`

sort函数：对指定区间的所有元素进行排序。结合vector使用，例如sort(vector.begin(), vector.end(), cmp)。sort函数默认对整型数据进行升序排列。

```c++
#include <algorithm>
#include <vector>
using namespace std;
struct node {
  int a, b;
}
bool cmp1(int a, int b) {
  return a > b;  //降序   return a < b则为升序
}
bool cmp2(node a, node b) {
  if(a.a != b.a)
    return a.a < b.a;
  else
    return a.b < b.b;
}
sort(begin, end)
sort(begin, end, cmp)
```

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
void post2pre(int root, int start, int end, int depth) {
  //root表示子树根节点在后序post中的下标
  //start和end表示子树的最左边和最右边在中序in中的下标
  if(start > end) return ;
  int i = start;
  while(i < end && in[i] != post[root]) i++;
  //先压入根节点
  pre.push_back(post[root]);
  level[depth] = post[root];
  //处理前半段，即左子树：新根为 root-1-(end-i)，起点为 start，终点为 i-1
  post2pre(root - 1 - end + i, start, i - 1, depth * 2);
  //处理后半段，即右子树：新根为 root-1，起点为 i+1，终点为 end
  post2pre(root - 1, i + 1, end, depth * 2 + 1);
}
  //应用
  post2pre(n - 1, 0, n - 1, 1);  //根节点为1层
  //顺序输出pre，即是前序序列
  //也是得到层序遍历序列，level需初始化，并选择判断后输出
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

### 6)递归函数及其思想

### 7)最短路径，Dijkstra算法

1) 利用容器存放路径信息，并保存在pre数组(其类型为vector<int>)中。**pre[i]** 中i表示当前结点，pre[i]中的值表示前一结点。因为，最短路径可以不唯一，利用vector可以保存多条路径。

2) dis[n]表示当前结点距离起点的距离。visit[n]数组，表示每个结点的遍历情况。

3) 利用对称矩阵e(n*n)，保存边的信息。

4）Dijkstra算法的思想：先找起点，然后寻找未经过的下一结点。

```c++
#include <cstido>
#include <vector>
#include <algorithm>
const int inf = 99999999;
int e[n][n], dis[n];
bool visit[n] = {false};
vector<int> pre[n];
//s表示起点坐标
int main() {
  fill(e, e + n * n, inf);
  fill(dis, dis + n);
  dis[s] = 0;
  for(int i = 0; i < n; i++) {
    int u = -1, minn = inf;
    for(int j = 0; j < n; j++) {
      if(visit[j] == false && dis[j] < minn) {
        u = j;  //起点，前一结点
        minn = j;
      }
    }
    if(u == -1) break;
    visit[u] = true;
    //下一结点
    for(int v = 0; v < n; v++) {
      if(visit[v] == false && e[u][v] != inf) {
        if(dis[u] + e[u][v] < dis[v]) {
          dis[v] = dis[u] + e[u][v];
          pre[v].clear();
          pre[v].push_back(u);
        } else if(dis[u] + e[u][v] == dis[v]) {
          pre[v].push_back(u);
        }
      }
    }
  }
}
```

### 8）深度优先搜索，使用vector

使用vector对象时，利用v数组(vector<int> v[n],n为结点个数)保存结点信息（前一结点或下一结点）。针对不同的数据结构，其终止条件不一样。如下所示：

1）如果数据结构是树类型。算法起点为 **根结点root**，终点为 **叶子结点**。常用于计算树的深度，每层的结点个数。

```c++
//此种情况，不用区分左右子树
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[n];
vector<int> book[n];
int maxdepth = -1;
void DFS(int index, int depth) {
  //index为根结点所在坐标
  if(v[index].size() == 0) {  //叶子结点
    book[depth]++;
    maxdepth = max(depth, maxdepth);
    return ;
  } else {
    for(int i = 0; i < v[index].size(); i++) {
      DFS(v[index][i], depth + 1);
    }
  }
}
```
2）同样也是树类型，区分左右子树时。

3）结合图论知识，找出路径问题。**对于每一条路径，其包含起点和终点**。因此，可以使用vector数组来保存路径信息。需要注意的是，**v数组中保存的是前一结点，还是下一结点，决定其输出顺序**。

```c++
//此程序参照 1018题
#include <cstdio>
#include <vector>
vector<int> pre[n];  //pre表示满足最短路径的条件下，当前结点的前一结点信息（形成树，供dfs使用）
vector<int> path, temppath;
void dfs(int v) {  //传入目标结点，即终点
  if(v == 0) {  //结束条件为，找到起点，即一条完整的路径。那么，关于路径上的计算问题，均在此处理
    temppath.push_back(v);
    int need = 0, back = 0;
    //求取路径的need和back
    for(int i = temppath.size() - 1; i >= 0; i--) {
      int id = temppath[i];
      if(weight[id] > 0) {  //车辆多余，需要带回
        back += weight[id];
      }
      else {  //车辆不足需要补充
        if(back > (0 - weight[id])) {  //用back补充不足车辆
          back += weight[id];
        } else { //需要携带补充
          need += ((0 - weight) - back);
          back = 0;   //back清零
        }
      }
    }
    //判断need和back
    if(need < minNeed) {
      minNeed = need;
      minBack = back;
      path = temppath;
    }
    else if(need == minNeed && back < minBack) {
      minBack = back;
      path = temppath;
    }
    temppath.pop_back();
    return ;
  }
  temppath.push_back(v);
  for(int i = 0; i < pre[v].size(); i++)  //因为最短路径可能不唯一，逐一使用dfs算法，并递归
    dfs(pre[v][i]);
  temppath.pop_back();
}
```

### 9）广度优先搜索

在二叉树里面，
