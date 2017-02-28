#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct TREE {
  int value;
  struct TREE *left, *right;
};
struct TREE* rightRotate(struct TREE *tree) {
  struct TREE *temp = tree->left;
  tree->left = tree->right;
  temp->right = tree;
  return tree;
}
struct TREE* leftRotate(struct TREE *tree) {
  struct TREE *temp = tree->right;
  tree->right = tree->left;
  temp->left = tree;
  return tree;
}
struct TREE* leftright(struct TREE *tree) {
  tree->left = leftRotate(tree->left);
  tree = rightRotate(tree);
  return tree;
}
struct TREE* rightleft(struct TREE *tree) {
  tree->right = rightRotate(tree->right);
  tree = leftRotate(tree);
  return tree;
}
int getHeight(struct TREE *tree) {
  if(tree == NULL)
    return 0;
  else {
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    return l > r ? l + 1 : r + 1;
  }
}
struct TREE* insertvalue(struct TREE *tree, int value) {
  if(tree == NULL) {
    tree = new struct TREE();
    tree->value = value;
    return tree;
  }
  if(value < tree->value) {
    tree->left = insertvalue(tree->left, value);
    int lenl = getHeight(tree->left);
    int lenr = getHeight(tree->right);
    if(lenl - lenr >= 2) {
      if(value < tree->left->value)
        tree = rightRotate(tree);
      else
        tree = leftright(tree);
    }
  }
  else {
    tree->right = insertvalue(tree->right, value);
    int lenl = getHeight(tree->left);
    int lenr = getHeight(tree->right);
    if(lenl - lenr >= 2) {
      if(value > tree->right->value)
        tree = leftRotate(tree);
      else
        tree = rightleft(tree);
    }
  }
  return tree;
}
int iscomplete = 1, after = 0;
vector<int> levelorder(struct TREE *tree) {
  vector<int> v;
  queue<struct TREE*> q;
  q.push(tree);
  while(!q.empty()) {
    struct TREE *temp = q.front();
    q.pop();
    v.push_back(temp->value);
    if(temp->left != NULL) {
      if(after) {
        iscomplete = 0;
      }
      q.push(temp->left);
    } else {
      after = 1;
    }
    if(temp->right != NULL) {
      if(after) {
        iscomplete = 0;
      }
      q.push(temp->right);
    } else {
      after = 1;
    }
  }
  return v;
}
void print(vector<int> v) {
  for(int i = 0; i < v.size(); i++) {
    if(i == 0)
      printf("%d", v[i]);
    else
      printf(" %d", v[i]);
  }
  printf("\n");
}
int main() {
  int n;
  scanf("%d", &n);
  struct TREE *tree = NULL;
  for(int i = 0; i < n; i++) {
    int temp = 0;
    scanf("%d", &temp);
    tree = insertvalue(tree, temp);
  }
  vector<int> v = levelorder(tree);
  print(v);
  if(iscomplete)
    printf("YES");
  else
    printf("NO");
  return 0;
}
