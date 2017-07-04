#include <iostream>
using namespace std;
struct Node {
  int val;
  Node* next;
};

// Delete alternate nodes of a Linked List
Node* DelteAlternate(Node *phead) {
  if(phead == NULL || phead->next == NULL)
    return phead;
  Node *pnew = phead;
  while(pnew && pnew->next) {
    Node *pnext = pnew->next->next;
    free(pnew->next);
    pnew->next = pnext;
    pnew = pnew->next;
  }
  return phead;
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
  int n, temp;
  Node *head1 = NULL;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    head1 = InsertBack(head1, temp);
  }
  Print(head1);
  //head = Intersection(head1, head2);
  head1 = DelteAlternate(head1);
  Print(head1);
  return 0;
}
