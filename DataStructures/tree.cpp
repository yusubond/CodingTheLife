#include <iostream>
#include <vector>
using namespace std;
struct Tree {
  int val;
  Tree *left, *right;
};
/*
功能：树的建立
 */
Tree *Insert(Tree *tree, int value) {
  if(tree == NULL) {
    tree = new Tree();
    tree->val = value;
    return tree;
  }
  if(value < tree->val)
    tree->left = Insert(tree->left, value);
  else
    tree->right = Insert(tree->right, value);
  return tree;
}
/*
功能：树的前序遍历
 */
vector<int> PreOrder(Tree *tree) {
  static vector<int> v;
  if(tree == NULL) return;
  else {
    v.push_back(tree->val);
    
  }
  vector<int> v;

}
void Print(Tree *root) {
  if(root == NULL)
    return;
  else {
    cout << root->val << endl;
    Print(root->left);
    Print(root->right);
  }
}
void PrintVector(vector<int> v) {
  if(v.size() == 0)
    return ;
  else {
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      if(it == v.begin())
        cout << *it;
      else
        cout << " " << *it;
    }
  }
  cout << endl;
}
int main() {
  Tree *root = NULL;
  int n, temp;
  vector<int> num;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    root = Insert(root, temp);
  }
  PrintVector(num);
  return 0;
}
