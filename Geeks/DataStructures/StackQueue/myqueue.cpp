#include <iostream>
#include <queue>
using namespace std;

/*
queue 的基本操作有：
入队，如例：q.push(x); 将x 接到队列的末端。
出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。
访问队首元素，如例：q.front()，即最早被压入队列的元素。
访问队尾元素，如例：q.back()，即最后被压入队列的元素。
判断队列空，如例：q.empty()，当队列空时，返回true。
访问队列中的元素个数，如例：q.size()
 */

int main() {
  queue<int> q;
  q.push(1);
  cout << q.size() << endl;
  q.pop();
  q.push(2);
  q.push(3);
  cout << q.size() << endl;
  q.pop();
  q.push(4);
  q.push(5);
  cout << q.size() << endl;
  cout << q.front() << endl;
  cout << q.back() << endl;
  return 0;
}
