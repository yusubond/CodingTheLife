#include <cstdio>
using namespace std;
struct TREE {
  int value;
  struct TREE *left, *right;
};
TREE *rightRotate(TREE *tree) {
  struct TREE *temp = tree->left;
  tree->left = temp->right;
  temp->right = tree;
  return temp;
}
TREE *leftRotate(TREE *tree) {
  struct TREE *temp = tree->right;
  tree->right = temp->left;
  temp->left = tree;
  return temp;
}
TREE *leftrightRotate(TREE *tree) {
  tree->left = leftRotate(tree->left);
  tree = rightRotate(tree);
  return tree;
}
TREE *rightleftRotate(TREE *tree) {
  tree->right = rightRotate(tree->right);
  tree = leftRotate(tree);
  return tree;
}
int getHeight(TREE *tree) {
  if(tree == NULL) {
    return 0;
  } else {
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    return l > r ? l + 1 : r + 1;
  }
}
TREE* insert(TREE *tree, int value) {
  if(tree == NULL) {
    tree = new TREE();
    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
  }
  if(value <= tree->value) {
    tree->left = insert(tree->left, value);
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    if(l - r >= 2) {
      if(value <= tree->left->value)
        tree = rightRotate(tree);
      else
        tree = leftrightRotate(tree);
    }
  }
  if(value > tree->value) {
    tree->right = insert(tree->right, value);
    int l = getHeight(tree->left);
    int r = getHeight(tree->right);
    if(r - l >= 2) {
      if(value <= tree->right->value)
        tree = rightleftRotate(tree);
      else
        tree = leftRotate(tree);
    }
  }
  return tree;
}
int main() {
  int n, temp;
  scanf("%d", &n);
  if(n == 0)
    printf("0");
  struct TREE *tree = NULL;
  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    tree = insert(tree, temp);
  }
  printf("%d", tree->value);
  return 0;
}
