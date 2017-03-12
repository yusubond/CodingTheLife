#include <cstdio>
#include <vector>
using namespace std;
struct Node{
  int data;
  Node *next;
};
struct myList{
  Node *head;
public:
  void InsertList(int predata, int data) {
    Node *p, *q, *s;
    s = (Node *)new(Node);
    s->data = data;
    p = head;
    if(head == NULL) {
      head = s;
      s->next = NULL;
    } else {
      if(p->data == predata) {
        s->next = p;
        head = s;
      } else {
        while(p->data != predata && p->next != NULL) {
          q = p;
          p = p->next;
        }
        if(p->data == predata) {
          q->next = s;
          s->next = p;
        } else {
          p->next = s;
          s->next = NULL;
        }
      }
    }
  }
  void DeleteList();
  void PrintList() {
    Node *p;
    p = head;
    while(head != NULL) {
      printf("%d ", p->data);
      p = p->next;
    }
  }
  Node *GetHead();
};
int main() {
  int n;
  vector<int> v;
  scanf("%d", &n);
  v.resize(n);
  myList my;
  for(int i = 0; i <n; i++) {
    scanf("%d", &v[i]);
    //printf(" %d", v[i]);
    my.InsertList(-1, v[i]);
  }
  my.PrintList();
}
