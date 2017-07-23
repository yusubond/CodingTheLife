#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
bool CheckBalance(char str[]) {
  stack<char> s;
  char a, b, c;
  for(int i = 0; i < strlen(str); i++) {
    if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
      s.push(str[i]);
    } else {
      switch(str[i]) {
        case ')':
          a = s.top();
          s.pop();
          if(a == '{' || a == '[')
            cout << "Not Balanced";
          break;
        case '}':
          b = s.top();
          s.pop();
          if(b == '(' || b == '[')
            cout << "Not Balanced";
          break;
        case ']':
          c = s.top();
          s.pop();
          if(c == '(' || c == '{')
            cout << "Not Balanced";
          break;
      }
    }
  }
  if(s.empty())
    return true;
  else
    return false;
}
int main() {
  char expr[]="{()}[[]";
  if(CheckBalance(expr))
    cout<<"Balanced";
  else
    cout<<"Not Balanced";
  return 0;
}
