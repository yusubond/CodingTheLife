#include <iostream>
#include <vector>
using namespace std;
struct node {
  int key;
  node *next;
};
int main() {
  node *Head = NULL;
  node *p1 = Head;
  vector<int> v;
  int temp;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    s = (node *)new(node);
    s->key = temp;
  }
  return 0;
}
