#include <iostream>
using namespace std;
// 双链表
struct Node {
  struct Node *pre, *next;
  int val;
};
// 栈结构
struct MyStack {
  struct Node *head;
  struct Node *mid;
  int count;
};
// 初始化
struct MyStack *CreateStack() {
  MyStack *ms = (MyStack*)malloc(sizeof(struct MyStack));
  ms->count = 0;
  return ms;
}
// 入栈
void Push(struct MyStack *ms, int x) {
  struct Node *data = (struct Node*)malloc(sizeof(struct Node));
  data->val = x;
  data->pre = NULL;
  data->next = ms->head;
  ms->count += 1;
  // 第一个元素
  if(ms->count == 1) {
    ms->mid = data;
  } else {
    // 让栈顶的元素指向新元素
    ms->head->pre = data;
    // 当有奇数个元素时，mid指针才发生一次移动
    if(ms->count & 1)
      ms->mid = ms->mid->pre;
  }
  ms->head = data;
}
// 出栈
int Pop(struct MyStack *ms) {
  if(ms->count == 0) {
    cout << "Stack is Empty" << endl;
    return -1;
  }
  struct Node *temp = ms->head;
  int x = temp->val;
  ms->head = temp->next;
  if(ms->head != NULL)
    ms->head->pre = NULL;
  ms->count -= 1;
  // 元素个数由奇数变为偶数时，mid指针需要移动
  if(!(ms->count & 1))
    ms->mid = ms->mid->next;
  free(temp);
  return x;
}
// 取栈中元素
int FindMiddle(struct MyStack *ms) {
  if(ms->count == 0) {
    cout << "Stack is Empty" << endl;
    return -1;
  } else {
    return ms->mid->val;
  }
}
int DeleteMiddle(struct MyStack *ms) {
  if(ms->count == 0) {
    cout << "Stack is Empty" << endl;
    return -1;
  }
  struct Node *temp = ms->mid;
  int x = temp->val;
  ms->count -= 1;
  // 元素个数由偶数变为奇数，mid指针向pre方向移动
  if((ms->count) & 1) {
    ms->mid = temp->pre;
    if(ms->count == 1) {
      ms->mid->next = NULL;
    } else {
    temp->next->pre = ms->mid;
    ms->mid->next = temp->next;
    }
  } else {
  // 元素个数由奇数变为偶数，mid指针向next方向移动
  if(ms->count == 0) {
    ms->head = NULL;
    ms->mid = NULL;
  } else {
    ms->mid = temp->next;
    temp->pre->next = ms->mid;
    ms->mid->pre = temp->pre;
    }
  }
  free(temp);
  return x;
}
int main() {
  struct MyStack *ms = CreateStack();
  Push(ms, 1);
  cout << FindMiddle(ms) << endl;
  Push(ms, 2);
  cout << FindMiddle(ms) << endl;
  Push(ms, 3);
  cout << FindMiddle(ms) << endl;
  cout << DeleteMiddle(ms) << endl;
  cout << FindMiddle(ms) << endl;
  cout << DeleteMiddle(ms) << endl;
  cout << DeleteMiddle(ms) << endl;
  return 0;
}
