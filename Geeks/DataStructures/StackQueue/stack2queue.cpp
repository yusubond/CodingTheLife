#include <iostream>
#include <stack>
using namespace std;
// Using Stack implement the Queue's Operations
// Stack's Operations: s.push(x) s.pop() s.top() s.empty() s.size()
// Queue's Operations: q.push(x) q.pop() q.front() q.back() q.empty() q.size()
class MyQueue {
private:
  stack<int> s;   // 用于入队
  stack<int> s2;  // 用于出队
public:
  void Push(int x);
  void Pop();
  int Front();
  int Back();
  bool Empty();
  int Size();
};
// 入队
void MyQueue::Push(int x) {
  s.push(x);
}
// 出队
void MyQueue::Pop() {
  if(s2.empty()) {
    if(s.empty()) {
      cout << "The Queue is Empty" << endl;
      return;
    } else {
      while(!s.empty()) {
        s2.push(s.top());
        s.pop();
      }
    }
  }
  if(!s2.empty()) {
    s2.pop();
  }
}
// 获取队首元素
int MyQueue::Front() {
  if(s2.empty()) {
    if(s.empty()) {
      cout << "The Queue is Empty" << endl;
      return -1;
    } else {
      while(!s.empty()) {
        s2.push(s.top());
        s.pop();
      }
    }
  }
  if(!s2.empty()) {
    return s2.top();
  }
}
// 获取队尾元素
int MyQueue::Back() {
  if(s.empty()) {
    if(s2.empty()) {
      cout << "The Queue is Empty" << endl;
      return -1;
    } else {
      while(!s2.empty()) {
        s.push(s2.top());
        s2.pop();
      }
    }
  }
  if(!s.empty()) {
    return s.top();
  }
}
// 判断队列是否为空
bool MyQueue::Empty() {
  return (s.empty() && s2.empty());
}
// 获取栈中元素的个数
int MyQueue::Size() {
  return (s.size() + s2.size());
}

int main() {
  MyQueue q;
  cout << q.Front() << endl;
  cout << q.Back() << endl;
  q.Push(1);
  q.Push(2);
  cout << q.Size() << endl;
  q.Pop();
  cout << q.Size() << endl;
  q.Push(3);
  q.Push(4);
  cout << q.Front() << endl;
  cout << q.Back() << endl;
  cout << q.Size() << endl;
  return 0;
}
