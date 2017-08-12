#include <iostream>
#include <stack>
using namespace std;

bool BSTCheck(int pre[], int n) {
  stack<int> s;
  int root = INT_MIN;
  for(int i = 0; i < n; i++) {
    if(pre[i] < root)
      return false;
    while(!s.empty() && s.top() < pre[i]) {
      root = s.top();
      s.pop();
    }
    s.push(pre[i]);
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  int pre[n];
  for(int i = 0; i < n; i++)
    cin >> pre[i];
  if(BSTCheck(pre, n))
    cout << "True" << endl;
  else
    cout << "False" << endl;
  return 0;
}
