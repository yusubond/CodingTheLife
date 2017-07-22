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
// Delete nodes which have a greater value on right side
Node DeleteSmallRight(Node *phead) {
  Node *pcur = phead;
  Node *maxnode = phead;
  Node *temp = NULL;
  while(pcur != NULL && pcur->next != NULL) {
    if(pcur->next->val < maxnode->val) {
      temp = pcur->next;
      pcur->next = temp->next;
      free(temp);
    } else {
      pcur = pcur->next;
      maxnode = pcur;
    }
  }
}
Node *Reverse(Node *phead) {
  if(phead == NULL || phead->next == NULL)
    return phead;
  Node *p = phead;
  Node *newhead = NULL;
  Node *pre = NULL;
  while(p != NULL) {
    Node *pnext = p->next;
    p->next = pre;
    pre = p;
    p = pnext;
  }
  newhead = pre;
  return newhead;
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
  headb = Reverse(headb);
  DeleteSmallRight(headb);
  Print(headb);
  headb = Reverse(headb);
  Print(headb);
  return 0;
}
