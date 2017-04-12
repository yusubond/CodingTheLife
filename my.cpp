#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> v;
  for(int i = 0; i < 10; i++)
    v.push_back(i * i);
  for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    cout << *it;
  return 0;
}
