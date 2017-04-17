#include <iostream>
using namespace std;
struct Node {
  int val;
  Node *next;
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
/*
功能：“快行指针”，后一半元素插空至前一半元素
 */
Node *QuickInsert(Node *phead) {
  if(phead == NULL || phead->next == NULL) return phead;
  Node *p1 = phead;
  Node *p2 = phead;
  int flag = 0;
  while(p1->next != NULL && p1->next->next != NULL) {
    p1 = p1->next->next;
    p2 = p2->next;
  }
  if(p1->next == NULL) {
    flag = 1;
  }
  p1 = phead;
  p2 = p2->next;
  while(p2->next != NULL) {
    Node *ptemp = p1->next;
    Node *pNext = p2->next;
    p1->next = p2;
    p2->next = ptemp;
    p2 = pNext;
    p1 = ptemp;
  }
  if(flag) {
    Node *ptemp = p1->next;
    ptemp->next = NULL;
    p1->next = p2;
    p2->next = ptemp;
  } else {
    p1->next = p2;
  }
  return phead;
}
void print(Node* phead) {
  if(phead != NULL)
    cout << phead->val;
  Node *p = phead->next;
  while(p != NULL) {
    cout << " " << p->val;
    p = p->next;
  }
  cout << endl;
}
int main() {
  Node *head = NULL;
  int n, temp;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    head = InsertBack(head,temp);
  }
  print(head);
  head = QuickInsert(head);
  print(head);
  return 0;
}
