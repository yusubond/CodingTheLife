## 链表

### 基本元素

```
struct Node {
  int val;
  Node *next;
};
```

### 基本操作

链表的基本操作，包括建立，删除，插入，反转，求取长度

1）链表的建立，包括两种：**前序插入** 和 **后序插入**

```
/*
功能：链表的建立
参数：输入链表头指针，返回链表头指针
说明：将新元素插入到整个链表的最后面
第一步，建立新节点；第二步，将新节点加入到链表的尾部
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
参数：输入链表头指针，返回链表头指针
说明：将新元素加入到整个链表的最前面
第一步，建立新节点；第二步，将新节点指向链表的头指针
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
参数：链表头指针，匹配元素，新元素
说明：当匹配元素存在时，将元素插入到位置的后面；否则插入到整个链表的后面
第一步，建立新节点；第二步，查找匹配元素并插入新元素，无需保存前驱节点
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
参数：表链表头指针，匹配元素，新元素
说明：当位置存在时，将元素插入到位置的前面；否则，插入到整个链表的后面
第一步，建立新节点；第二步，查找匹配元素并插入新元素，无需保存前驱节点
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

3) 链表的删除

```
/*
功能：链表的删除
参数：表头，元素
说明：删除某个元素，若无此元素则不进行任何操作
 */
Node *Delete(Node *phead, int target) {
  if(phead == NULL) return phead;
  Node *pNode = phead;
  if(pNode->val == target) {
    Node *ptemp = pNode->next;
    pNode->next = NULL;
    delete pNode;
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
  delete p;
  return phead;
}
```

4) 链表的反转

```
/*
功能：反转链表
参数：链表的头指针，返回链表的头指针
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
```
### 链表排序 (冒泡、选择，插入、快速，归并)

**插入排序**：直接交换节点

```
/*
功能：插入排序
参数：传入链表头指针作为参数，返回排序后的头指针
说明：时间复杂度O(n^2)，空间复杂度O(1)
第一步：选择插入的位置；第二步：如果在已排序的链表的尾部，则直接加入到尾部，否则，插入到选好的位置。注意：需要保存前驱节点。
 */
Node *InsertSort(Node *phead) {
  if(phead == NULL || phead->next == NULL) return phead;
  Node *p = phead->next, *pstart = phead, *pend = phead;
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
  return phead;
}
```

**选择排序**：

```
/*
功能：选择排序(选择未排序序列中的最值，然后放到已排序的最前面或最后面，只交换节点的值)
参数：输入链表的头指针，返回排序后的头指针
说明：时间复杂度O(n^2)，空间复杂度O(1)
 */
Node *SelectSort(Node *phead) {
  if(phead == NULL || phead->next == NULL) return phead;
  Node *pend = phead;
  while(pend->next != NULL) {
    Node *minNode = pend->next;
    Node *p = minNode->next;
    while(p != NULL) {
      if(p->val < minNode->val)
        minNode = p;
      p = p->next;
    }
    swap(minNode->val, pend->val);
    pend = pend->next;
  }
  return phead;
}
```

**快速排序**

```
/*
功能：快速排序，链表指向下一个元素的特性，partition是选择左闭合区间
第一步，partiton，因为链表不支持随机访问元素，因此partiton中选取第一个节点值作为基准
第二步，排序
参数：输入链表头指针，输出排序后的头指针
说明：平均时间复杂度O(nlogn)，空间复杂度O(1)
 */
Node *Partition(Node *low, Node *high) {
  //左闭合区间[low, high)
  int base = low->val;
  Node *location = low;
  for(Node *i = low->next; i != high; i = i->next) {
    if(i->val > base) {
      location = location->next;
      swap(location->val, i->val);
    }
  }
  swap(low->val, location->val);
  return location;
}
void QuickList(Node *phead, Node *tail) {
  //左闭合区间[phead, tail)
  if(phead != tail && phead->next != tail) {
    Node *mid = Partition(phead, tail);
    QuickList(phead, mid);
    QuickList(mid->next, tail);
  }
}
Node *QuickSort(Node *phead) {
  if(phead == NULL || phead->next == NULL) return phead;
  QuickList(phead, NULL);
  return phead;
}
```

**归并排序**

```
/*
功能：归并排序，交换链表节点
第一步：先写归并函数；第二步：利用快慢指针找到链表中点，然后递归对子链进行排序
参数：输出链表的头指针，输出排序后的头指针
说明：时间复杂度O(nlogn)，空间复杂度O(1)。归并排序应该算是链表排序中最佳的选择，保证最好和最坏的时间复杂度都是O(nlogn)，而且在将空间复杂度由数组中O(n)，降到链表中的O(1)
 */
Node *merge(Node *phead1, Node *phead2) {
  if(phead1 == NULL) return phead2;
  if(phead2 == NULL) return phead1;
  Node *res, *p;
  if(phead1->val < phead2->val) {
    res = phead1;
    phead1 = phead1->next;
  } else {
    res = phead2;
    phead2 = phead2->next;
  }
  p = res;
  while(phead1 != NULL && phead2 != NULL) {
    if(phead1->val < phead2->val) {
      p->next = phead1;
      phead1 = phead1->next;
    } else {
      p->next = phead2;
      phead2 = phead2->next;
    }
    p = p->next;
  }
  if(phead1 != NULL) p->next = phead1;
  else if(phead2 != NULL) p->next = phead2;
  return res;
}
Node *MergeSort(Node *phead) {
  if(phead == NULL || phead->next == NULL) return phead;
  Node *fast = phead;
  Node *slow = phead;
  while(fast->next != NULL && fast->next->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }
  fast = slow;
  slow = slow->next;
  fast->next = NULL;
  fast = MergeSort(phead);
  slow = MergeSort(slow);
  return merge(fast, slow);
}
```
