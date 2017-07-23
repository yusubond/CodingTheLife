#include <iostream>
#include <stack>
using namespace std;
void SortedInsert(stack<int> &s, int x)
{
  if(s.empty() || x > s.top()) {
    s.push(x);
    return;
  }
  int temp = s.top();
  s.pop();
  SortedInsert(s, x);
  s.push(temp);
}
// 排序
void StackSort(stack<int> &s) {
  if(!s.empty()) {
    int temp = s.top();
    s.pop();
    StackSort(s);
    SortedInsert(s, temp);
  }
}
int main() {
  stack<int> s;
  s.push(4);
  s.push(3);
  s.push(2);
  s.push(1);
  while(!s.empty()) {
    int x = s.top();
    s.pop();
    cout << x << endl;
  }
  cout << endl;
  s.push(4);
  s.push(3);
  s.push(2);
  s.push(1);
  StackSort(s);
  while(!s.empty()) {
    int x = s.top();
    s.pop();
    cout << x << endl;
  }
  return 0;
}
