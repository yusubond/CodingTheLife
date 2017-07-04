#include <iostream>
using namespace std;
struct Node {
  int val;
  Node* next;
};
Node* InsertBack(Node *phead, int value) {
  Node *s;
  s = (Node*)new(Node);
  s->val = value;
  s->next = NULL;
  if(phead == NULL) {
    phead = s;
    return phead;
  } else {
    Node *p = phead;
    while(p->next != NULL) {
      p = p->next;
    }
    p->next = s;
    return phead;
  }
}
void Print(Node* phead) {
  if(phead == NULL) return;
  if(phead != NULL)
    cout << phead->val;
  Node *p = phead->next;
  while(p != NULL) {
    cout << " " << p->val;
    p = p->next;
  }
  cout << endl;
}
// Move last element to front of a given Linked List
Node *Last2Head(Node *phead) {
  if(phead == NULL || phead->next == NULL)
    return phead;
  Node *last = phead->next, *pre = phead;
  while(pre && last && last->next != NULL) {
    last = last->next;
    pre = pre->next;
  }
  pre->next = NULL;
  last->next = phead;
  phead = last;
  return phead;
}
int main() {
  int n, temp;
  Node *headb = NULL;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    headb = InsertBack(headb, temp);
  }
  cout << "初始链表：" << endl;
  Print(headb);
  headb = Last2Head(headb);
  Print(headb);
  return 0;
}
