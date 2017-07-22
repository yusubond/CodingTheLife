#include <iostream>
using namespace std;
struct Node {
  int val;
  Node* next;
};

// Intersection of two Sorted Linked Lists
Node* Intersection(Node *phead1, Node *phead2) {
  if(phead1 == NULL || phead2 == NULL)
    return NULL;
  Node *p1 = phead1, *p2 = phead2;
  Node *pNew = NULL, *p =NULL;
  int flag = 1;
  while(p1 && p2) {
    if(p1->val == p2->val) {
      if(flag) {
        pNew = p1;
        p = pNew;
        flag = 0;
      } else {
        p->next = p1;
        p = p->next;
      }
      p1 = p1->next;
      p2 = p2->next;
    } else if(p1->val < p2->val) {
      p1 = p1->next;
    } else {
      p2 = p2->next;
    }
  }
  p->next = NULL;
  return pNew;
}
// 递归实现
Node *SortIntersection(Node *phead1, Node *phead2) {
  if(phead1 == NULL || phead2 == NULL)
    return NULL;
  if(phead1->val < phead2->val)
    return SortIntersection(phead1->next, phead2);
  if(phead1->val > phead2->val)
    return SortIntersection(phead1, phead2->next);
  Node *result = (struct Node*)malloc(sizeof(struct Node));
  result->val = phead1->val;
  result->next = SortIntersection(phead1->next, phead2->next);
  return result;
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
int main() {
  int n, m, temp;
  Node *head1 = NULL, *head2 = NULL, *head = NULL;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    head1 = InsertBack(head1, temp);
  }
  for(int i = 0; i < m; i++) {
    cin >> temp;
    head2 = InsertBack(head2, temp);
  }
  cout << "初始链表：" << endl;
  Print(head1);
  Print(head2);
  //head = Intersection(head1, head2);
  head = SortIntersection(head1, head2);
  Print(head);
  return 0;
}
