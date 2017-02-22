#include <iostream>
#include <string.h>
using namespace std;
string s1, s2;
int visit[128] = {0};
int main() {
  getline(cin, s1);
  getline(cin, s2);
  for(int i = 0; i < s1.length(); i++)
    visit[int(s1[i])]++;
  for(int i = 0; i < s2.length(); i++)
    visit[int(s2[i])]--;
  int count = 0;
  for(int i = 0; i < 128; i++) {
    if(visit[i] < 0) {
      count += visit[i] * (-1);
    }
  }
  if(count == 0)
    printf("Yes %d", s1.length() - s2.length());
  else
    printf("No %d", count);
  return 0;
}
