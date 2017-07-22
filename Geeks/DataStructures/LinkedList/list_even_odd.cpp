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
// **********************************
Node *EvenOdd(Node *phead) {
  if(phead == NULL || phead->next == NULL)
    return phead;
  Node *p = phead;
  Node *p1 = phead;
  Node *p2 = phead;
  p1->next = NULL;
  P2->next = NULL;
  while(p != NULL) {
    if((p->val % 2) == 0) {
      p1->next = p;
      p1 = p1->next;
    } else {
      p2->next = p;
      p2 = p2->next;
    }
    p = p->next;
  }
  p1->next = p
}
// **********************************

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
