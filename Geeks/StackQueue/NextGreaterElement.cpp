#include <iostream>
#include <stack>
using namespace std;

void NextGreaterElement(int arr[], int n) {
  if(n < 1)
    return;
  int temp[n];
  stack<int> s, s2;
  temp[n - 1] = -1;
  s.push(arr[n - 1]);
  s2.push(arr[n - 1]);
  int i, j;
  for(i = n - 2; i >= 0; i--) {
    s2.push(arr[i]);
    while(!s.empty()) {
      int x = s.top();
      if(arr[i] < x) {
        temp[i] = x;
        break;
      } else {
        s.pop();
      }
    }
    if(s.empty()) {
      temp[i] = -1;
    }
    s = s2;
  }
  for(i = 0; i < n; i++)
    cout << arr[i] << "--" << temp[i] << endl;;
}

int main() {
  int n, y;
  cin >> n;
  int data[n];
  for(int i = 0; i < n; i++)
    cin >> data[i];
  NextGreaterElement(data, n);
  return 0;
}
