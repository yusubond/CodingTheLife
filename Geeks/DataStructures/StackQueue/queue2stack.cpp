#include <iostream>
#include <queue>
using namespace std;
// Using Queue implement the Stack's Operations
// Queue's Operations: q.push(x) q.pop() q.front() q.back() q.empty() q.size()
// Stack's Operations: s.push(x) s.pop() s.top() s.empty() s.size()
class MyStack {
private:
  queue<int> q;
public:
  void Push(int x);
  void Pop();
  int Top();
  bool Empty();
  int Size();
};
// 压栈
void MyStack::Push(int x) {
  q.push(x);
}
// 出栈
void MyStack::Pop() {
  if(q.size() == 0) {
    cout << "The Stack is Empty" << endl;
    return;
  }
  if(q.size() == 1)
    q.pop();
  else {
    int n = q.size();
    while(n > 1) {
      q.push(q.front());
      q.pop();
      n--;
    }
    q.pop();
  }
}
// 获取栈顶元素
int MyStack::Top() {
  if(q.size() == 0) {
    cout << "The Stack is Empty" << endl;
    return -1;
  }
  if(q.size() == 1)
    return q.front();
  else {
    int n = q.size();
    while(n > 1) {
      q.push(q.front());
      q.pop();
      n--;
    }
    return q.front();
  }
}
// 判断栈是否为空
bool MyStack::Empty() {
  return q.empty();
}
// 获取栈中元素的个数
int MyStack::Size() {
  return q.size();
}

int main() {
  MyStack s;
  cout << s.Top() << endl;
  s.Push(2);
  cout << s.Top() << endl;
  s.Push(3);
  s.Push(4);
  cout << s.Size() << endl;
  s.Pop();
  cout << s.Size() << endl;
  cout << s.Top() << endl;
  cout << s.Empty() << endl;
  return 0;
}
