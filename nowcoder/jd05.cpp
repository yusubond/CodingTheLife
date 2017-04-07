/*
* Author: subond
* Time: 2017-04-07
* Question: 合并记录，map的使用
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  int n, s;
  while(cin >> n >> s) {
    map<int, int> buy, sell;
    for(int i = 0; i < n; i++) {
      string str;
      int p, q;
      cin >> str >> p >> q;
      if(str == "B") {
        if(buy.find(p) != buy.end())
          buy[p] += q;
        else
          buy[p] = q;
      } else if(str == "S") {
        if(sell.find(p) != sell.end())
          sell[p] += q;
        else
          sell[p] = q;
      }
    }
    int scount = sell.size() < s ? sell.size() : s;
    int bcount = buy.size() < s ? buy.size() : s;

    for(map<int, int>::reverse_iterator it = sell.rbegin(); scount > 0; it++, scount--)
      cout << "S " << it->first << " " << it->second << endl;
    for(map<int, int>::reverse_iterator it = buy.rbegin(); bcount > 0; it++, bcount--)
      cout << "B " << it->first << " " << it->second << endl;
  }
  return 0;
}
