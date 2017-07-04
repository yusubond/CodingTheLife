#include <iostream>
using namespace std;
struct Node {
  int val;
  Node* next;
};

// Pairwise swap elements of a given linked list
Node* Pairwise(Node *phead) {
  if(phead == NULL && phead->next == NULL)
    return phead;
  Node *pre = phead, *after = phead->next;
  while(pre && after) {
    int temp = pre->val;
    pre->val = after->val;
    after->val = temp;
    pre = after->next;
    if(pre != NULL)
      after = pre->next;
  }
  return phead;
}
Node* Pairwise2(Node **phead) {
  if((*phead) == NULL && (*phead)->next == NULL)
    return (*phead);
  Node *pre = (*phead), *cur = (*phead)->next;
  *phead = cur;
  while(true) {
    Node *next = cur->next;
    cur->next = pre;
    if(next == NULL || next->next == NULL) {
      pre->next = next;
      break;
    }
    pre->next = next->next;
    pre = next;
    cur = pre->next;
  }
}
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
Node *Last2Head(Node *phead) {
  if(phead == NULL && phead->next ==NULL)
    return NULL;
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
void Print2(Node *phead) {
  if(phead == NULL)
    return;
  Print2(phead->next);
  cout << phead->val << " ";
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
  //cout << "配对交换后为" << endl;
  //Pairwise2(&headb);
  //print(headb);
  return 0;
}
