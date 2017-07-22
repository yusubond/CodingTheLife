#include <iostream>
#include <stack>
using namespace std;
// Using Stack implement the Queue's Operations
// Stack's Operations: s.push(x) s.pop() s.size()
// Queue's Operations: q.push(x) q.pop() q.empty()
class MyQueue {
private:
  stack<int> s;   // 用于入队
  stack<int> s2;  // 用于出队
public:
  void Push(int x);
  void Pop(int &x);
  bool Empty();
};
// 入队
void MyQueue::Push(int x) {
  s.push(x);
}
// 出队
void MyQueue::Pop(int &x) {
  int temp;
  if(s2.size() == 0) {
    if(s.size() == 0) {
      cout << "The Queue is Empty" << endl;
    } else {
      while(s.size() > 0) {
        s.pop(&temp);
        s2.push(temp);
      }
    }
  }
  if(s2.size() != 0)
    s2.pop(&x);
}
// 判断队列是否为空
bool MyQueue::Empty() {
  return ((s.size() == 0) && (s2.size() == 0));
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
