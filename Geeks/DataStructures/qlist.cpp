/*
Author: subond
Time: 2017-04-18
题目来源：程序员面试金典
 */
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
/*
2.1题：移除未排序链表中的重复节点
代码分析：时间复杂度(n^2)，空间复杂度O(1)。
若可以使用临时缓冲区，可进行h每个节点加入hash映射，出现重复元素时，删除元素。
 */
Node *DeleteDouble(Node *phead) {
  if(phead == NULL || phead->next == NULL) return phead;
  Node *p = phead;
  while(p != NULL) {
    Node *pstart = p->next;
    Node *pre = p;
    while(pstart != NULL) {
      if(pstart->val == p->val) {
        Node *ptemp = pstart;
        ptemp->next = NULL;
        delete ptemp;
        pre->next = pstart->next;
      }
      pre = pstart;
      pstart = pstart->next;
    }
    p = p->next;
  }
  return phead;
}
/*
2.2题：实现一个算法，输出倒数第k个节点
代码分析："快慢指针"的用法
 */
Node *ReturnBackK(Node *phead, int k) {
  if(phead == NULL) return phead;
  if(k <= 0) return NULL;
  Node *pfast = phead, *pslow = phead;
  while(pfast != NULL) {
    if(k > 0) {
      pfast = pfast->next;
      k--;
    } else {
      pfast = pfast->next;
      pslow = pslow->next;
    }
  }
  //倒数第k个，还是倒数k个，区别是是否添加空指针
  pslow->next = NULL;
  if(k == 0) {
    return pslow;
  } else {
    return NULL;
  }
}
/*
2.4题：编写代码，以给定值x为基准将链表分为两部分，所有小于x的元素排在大于或等于x的前面
代码分析：
 */
Node *SortX(Node *phead, int x) {
  if(phead == NULL || phead->next == NULL) return phead;
  Node *before = NULL;
  Node *after = NULL;
  Node *beforeend = NULL;
  Node *afterend = NULL;
  Node *p = phead;
  while(p != NULL) {
    Node *pNext = p->next;
    p->next = NULL;
    if(p->val < x) {
      if(before == NULL) {
        before = p;
        beforeend = before;
      } else {
        beforeend->next = p;
        beforeend = p;
      }
    } else {
      if(after == NULL) {
        after = p;
        afterend = after;
      } else {
        afterend->next = p;
        afterend = p;
      }
    }
    p = pNext;
  }
  if(before == NULL)
    return after;
  else
    before->next = after;
  return before;
}
void print(Node* phead) {
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
  Node *head = NULL;
  int n, temp;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    head = InsertBack(head,temp);
  }
  print(head);
  //head = QuickInsert(head);
  //head = DeleteDouble(head);
  //head = ReturnBackK(head, 3);
  head = SortX(head, 10);
  print(head);
  return 0;
}
