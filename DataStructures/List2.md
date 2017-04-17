## 链表

链表操作的常用技巧。

1）”快行指针”

快行指针是指同时用两个指针来迭代访问链表，其中一个比另一个超前一些。“快”往往先走几步，或者与慢指针保持固定的距离。

一个例子：假设一个链表为a1->a2->a3->...->an->b1->b2->...->bn，将其重新排序为a1->b1->a2->b2->...->an->bn。

```
/*
功能：“快行指针”，后一半元素插空至前一半元素，注意后一半元素的个数不大于前一半元素的个数。
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
```
