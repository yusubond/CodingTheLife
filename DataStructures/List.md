## 链表

### 基本数据

```
struct node {
  int val;
  node *next;
};
```

### 基本操作

1）链表的建立，包括两种：**前序插入** 和 **后序插入**

```
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
```

2) 链表的插入，包括两种：在某个 **位置前插入** 和 **位置后插入**

```
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
```
