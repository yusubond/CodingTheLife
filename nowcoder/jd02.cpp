/*
* Author: subond
* TIme: 2017-04-07
* Question: map的使用，根据采购清单计算商品总价
 */
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(int a, int b) {
  return a > b;
}
int main() {
  int n, m, temp;
  while(cin >> n >> m) {
    int minp = 0, maxp = 0;
    vector<int> price(n);
    map<string, int> list;
    vector<int> num;
    for(int i = 0; i < n; i++)
      cin >> price[i];
    sort(price.begin(), price.end());

    map<string, int> item_count;
    string item;
    for(int i = 0; i < m; i++) {
      cin >> item;
      if(list.find(item) != list.end()) {
        list[item]++;
      } else {
        list.insert(make_pair(item, 1));
      }
    }
    for(map<string, int>::iterator it = list.begin(); it != list.end(); it++) {
      num.push_back(it->second);
    }
    sort(num.begin(), num.end(), cmp);
    for(int i = 0; i < num.size(); i++) {
      //printf("%d ", num[i]);
      minp += num[i] * price[i];
      maxp += num[i] * price[price.size() - 1 - i];
    }
    cout << minp << " "<< maxp << endl;
    price.clear();
    num.clear();
    list.clear();
  }
}
