#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main() {
  string line;
  while(getline(cin, line)) {
    if(line.begin() != line.end()) {
      auto it = line.begin();
      *it = toupper(*it);
    }
    cout << line << " " << strlen(line) << endl;
  }
  return 0;
}
