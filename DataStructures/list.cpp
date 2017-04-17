#include <iostream>
using namespace std;
struct Node {
  int val;
  Node* next;
};
/*
功能：链表的建立
说明：将新元素插入到整个链表的最后面
 */
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
功能：链表的建立
说明：将新元素加入到整个链表的最前面
 */
Node *InsertFront(Node *phead, int value) {
  Node *s;
  s = (Node*)new(Node);
  s->val = value;
  s->next = phead;
  phead = s;
  return phead;
}
/*
功能：链表的插入
参数：表头，位置，元素
说明：当位置存在时，将元素插入到位置的后面；否则插入到整个链表的后面
 */
Node *InsertAfter(Node *phead, int value1, int value2) {
  Node *s, *p;
  int flag = 0;
  s = (Node*)new(Node);
  s->val = value2;
  p = phead;
  while(p->next != NULL) {
    if(p->val == value1) {
      Node *ptemp = p->next;
      p->next = s;
      s->next = ptemp;
      flag = 1;
      break;
    } else {
      p = p->next;
    }
  }
  if(!flag) {
    s->next = NULL;
    p->next = s;
  }
  return phead;
}
/*
功能：链表的插入
参数：表头，位置，元素
说明：当位置存在时，将元素插入到位置的前面；否则，插入到整个链表的后面
 */
Node *InsertBefore(Node *phead, int value1, int value2) {
  Node *s;
  s = (Node*)new(Node);
  s->val = value2;
  int flag = 0;
  if(phead->val == value1) {
    s->next = phead;
    phead = s;
    return phead;
  }
  Node *p = phead;
  while(p->next != NULL) {
    if(p->next->val == value1) {
      Node *ptemp = p->next;
      p->next = s;
      s->next = ptemp;
      flag = 1;
      break;
    } else {
      p = p->next;
    }
  }
  if(!flag) {
    s->next = NULL;
    p->next = s;
  }
  return phead;
}
/*
功能：链表的删除
参数：表头，元素
说明：删除某个元素，若无此元素则不进行任何操作
 */
Node *Delete(Node *phead, int target) {
  if(phead->val == target) {
    Node *ptemp = phead->next;
    phead->next = NULL;
    phead = ptemp;
    return phead;
  }
  Node *p = phead->next;
  Node *pPre = phead;
  while(p != NULL) {
    if(p->val == target) {
      break;
    } else {
      pPre = p;
      p = p->next;
    }
  }
  pPre->next = p->next;
  p->next = NULL;
  return phead;
}
/*
功能：反转链表
 */
Node *Reverse(Node *phead) {
  Node *pReverseHead = NULL;
  Node *pNode = phead;
  Node *pPre = NULL;
  while(pNode != NULL) {
    Node *pNext = pNode->next;
    pNode->next = pPre;
    pPre = pNode;
    pNode = pNext;
  }
  pReverseHead = pPre;
  return pReverseHead;
}
/*
功能：插入排序
参数：传入链表头指针作为参数，返回排序后的头指针
说明：时间复杂度O(n^2)，空间复杂度O(1)
 */
Node *InsertSort(Node *phead) {
  if(phead == NULL || phead->next == NULL) return phead;
  Node *p = phead->next, *pstart = new Node, *pend = phead;
  pstart->next = phead;
  while(p != NULL) {
    Node *ptemp = pstart->next, *pre = pstart;
    while(ptemp != p && p->val >= ptemp->val) {
      ptemp = ptemp->next;
      pre = pre->next;
    }
    if(ptemp == p)
      pend = p;
    else {
      pend->next = p->next;
      p->next = ptemp;
      pre->next = p;
    }
    p = pend->next;
  }
  phead = pstart->next;
  delete pstart;
  return phead;
}
/*
功能：计算链表长度
参数：输入表头，输出无符号整型
 */
unsigned Length(Node *phead) {
  Node *p = phead;
  unsigned len = 0;
  while(p != NULL) {
    len++;
    p = p->next;
  }
  return len;
}
/*
功能：打印链表
说明：各个元素之间用空格隔开，末尾无空格
 */
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
  int n, temp;
  Node *headb = NULL;
  Node *headf = NULL;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> temp;
    headb = InsertBack(headb, temp);
    headf = InsertFront(headf, temp);
  }
  print(headb);
  //print(headf);
  headb = InsertAfter(headb, 4, 12);
  //headf = InsertBefore(headf, 4, 12);
  print(headb);
  //print(headf);
  headb = Delete(headb, 3);
  //headf = Delete(headf, 8);
  print(headb);
  Node *headr = Reverse(headb);
  print(headr);
  headr = InsertSort(headr);
  print(headr);
  //print(headf);
  cout << "Length: " << Length(headr) << endl;
  return 0;
}
