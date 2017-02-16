#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct node {
  int left, right, value;
};
vector<node> tree;
vector<int> v;
int t = 0;
void inorder(int root) {
  //依次判断 根 左 右
  if(tree[root].left == -1 && tree[root].right == -1) {
    tree[root].value = v[t++];
    return;
  }
  if(tree[root].left != -1)
    inorder(tree[root].left);
  tree[root].value = v[t++];
  if(tree[root].right != -1)
    inorder(tree[root].right);
}
int main() {
  int n;
  scanf("%d", &n);
  tree.resize(n);
  v.resize(n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &tree[i].left, &tree[i].right);
  }
  for(int i = 0; i < n; i++)
    scanf("%d", &v[i]);
  sort(v.begin(), v.end());  //默认升序
  inorder(0);  //中序遍历及赋值
  //对tree进行层序遍历，并输出
  //使用 queue，依次压入每一层的值，并在下次循环时输出
  queue<int> q;
  q.push(0);
  printf("%d", tree[0].value);
  while(!q.empty()) {
    int index = q.front();
    q.pop();
    if(index != 0) printf(" %d", tree[index].value);
    if(tree[index].left != -1) q.push(tree[index].left);
    if(tree[index].right != -1) q.push(tree[index].right);
  }
  return 0;
}
