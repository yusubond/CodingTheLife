#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v(1000);
int maxdepth = -1;
struct TREE {
  int value;
  struct TREE *left, *right;
};
struct TREE* insert(struct TREE *tree, int value) {
  if(tree == NULL) {
    tree = new struct TREE();
    tree->value = value;
    tree->left = tree->right = NULL;
    return tree;
  }
  if(value <= tree->value)
    tree->left = insert(tree->left, value);
  if(value > tree->value)
    tree->right = insert(tree->right, value);
  return tree;
}
void dfs(struct TREE *tree, int depth) {
  if(tree == NULL) {
    maxdepth = max(depth, maxdepth);
    return;
  }
  v[depth]++;
  dfs(tree->left, depth + 1);
  dfs(tree->right, depth + 1);
}
int main() {
  int n, temp;
  scanf("%d", &n);
  if(n == 0) {
    printf("0");
  }
  struct TREE *tree = NULL;
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    tree = insert(tree, temp);
  }
  dfs(tree, 0);
  printf("%d + %d = %d", v[maxdepth - 1], v[maxdepth - 2], v[maxdepth - 1] + v[maxdepth - 2]);
  return 0;
}
