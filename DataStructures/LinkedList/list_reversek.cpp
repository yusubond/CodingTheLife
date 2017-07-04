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
// Reverse a Linked List in groups of given size
Node *Reversek(Node *phead, int k) {
  Node *p = phead;
  Node *pnext = NULL;
  Node *pre = NULL;
  int count = 0;
  while(p != NULL && count < k) {
    pnext = p->next;
    p->next = pre;
    pre = p;
    p = pnext;
    count++;
  }
  if(pnext != NULL)
    phead->next = Reversek(pnext, k);
  return pre;
}
// Reverse alternate K nodes in a Singly Linked List
Node *KReverse(Node *phead, int k) {
  Node *p = phead;
  Node *pnext = NULL;
  Node *pre = NULL;
  int count = 0;
  while(p != NULL && count < k) {
    pnext = p->next;
    p->next = pre;
    pre = p;
    p = pnext;
    count++;
  }
  if(phead != NULL) {
    // cout << phead->val << endl;
    phead->next = p;
  }
  count = 0;
  while(count < (k - 1) && p != NULL) {
    p = p->next;
    count++;
  }
  if(p != NULL)
    p->next = KReverse(p->next, k);
  return pre;
}
int main() {
  int n, temp, k;
  Node *headb = NULL;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    headb = InsertBack(headb, temp);
  }
  cout << "初始链表：" << endl;
  Print(headb);
  headb = KReverse(headb, k);
  Print(headb);
  return 0;
}
