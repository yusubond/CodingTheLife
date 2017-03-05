#include <iostream>
#include <set>
#include <cstring>
using namespace std;
int n, m, step;
set<string> s;
int main() {
  cin >> n >> step >> m;
  string str;
  if(n < m) {
    cout << "Keep going..." << endl;
  } else {
    int next = m;
    for(int i = 1; i <= n; i++) {
      cin >> str;
      if(i < next)
        continue;
      else if(i == next){
        if(s.find(str) == s.end()) {
          s.insert(str);
          printf("%s\n", str.c_str());
          next += step;
        } else {
          next += 1;
        }
      }
    }
  }
}
