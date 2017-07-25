#include <iostream>
using namespace std;
class MyQueue
{
private:
  int front, rear, size;
  unsigned capacity;
  int *array;
public:
  MyQueue(unsigned num);
  bool Push(int x);
  bool Pop();
  int Front();
  int Back();
  bool Empty();
  bool Full();
};
// 初始化
MyQueue::MyQueue(unsigned num) {
  capacity = num;
  array = new int[capacity];
  front = 0;
  rear = capacity - 1;
  size = 0;
}
bool MyQueue::Full() {
  if(size == capacity)
    return true;
  else
    return false;
}
bool MyQueue::Empty() {
  if(size == 0)
    return true;
  else
    return false;
}
// 入队
bool MyQueue::Push(int x) {
  if(size == capacity) {
    cout << "Queue is Overflow" << endl;
    return false;
  }
  rear = (rear + 1) % capacity;
  array[rear] = x;
  size += 1;
  return true;
}
// 出队
bool MyQueue::Pop() {
  if(size == 0) {
    cout << "Queue is Underflow" << endl;
    return false;
  }
  int x = array[front];
  front = (front + 1) % capacity;
  size -= 1;
  return x;
}
// 取队头元素
int MyQueue::Front() {
  if(size == 0) {
    cout << "Queue is Underflow" << endl;
    return -1;
  }
  return array[front];
}
// 取队尾元素
int MyQueue::Back() {
  if(size == 0) {
    cout << "Queue is Underflow" << endl;
    return -1;
  }
  return array[rear];
}
int main() {
  MyQueue mq(2);
  mq.Push(3);
  mq.Push(4);
  cout << mq.Front() << endl;
  cout << mq.Back() << endl;
  mq.Push(5);
  return 0;
}
