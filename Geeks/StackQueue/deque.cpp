#include <iostream>
#include <deque>
using namespace std;
int main() {
  deque<int> dq;
  dq.push_front(1);
  dq.push_front(2);
  dq.push_back(3);
  dq.push_back(4);
  dq.resize(10);
  dq.push_front(11);
  dq.push_back(22);

  cout << dq.size() << endl;
  for(deque<int>::iterator it = dq.begin(); it != dq.end(); it++) {
    cout << *it << " ";
  }
  return 0;
}
